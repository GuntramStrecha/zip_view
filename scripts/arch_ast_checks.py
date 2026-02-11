#!/usr/bin/env python3
"""
Lightweight AST-based architecture checks using libclang (clang.cindex).

Checks performed:
 - virtual methods (ERROR)
 - dynamic_cast / typeid usage (ERROR)
 - new/malloc/free usage (WARNING)
 - std::unique_ptr / std::shared_ptr usage (WARNING)
 - throw inside noexcept functions (WARNING)

This script is a fallback for rules that are not fully covered by clang-tidy.

Usage: ./scripts/arch_ast_checks.py --compile-commands build/compile_commands.json

Returns exit code 0 on success, 1 if warnings found, 2 if errors found.
"""

import argparse
import json
import os
import subprocess
import sys
import tempfile
from collections import defaultdict

try:
    from clang import cindex
except Exception as e:
    print("ERROR: libclang (clang.cindex) is required. Install python clang bindings.\nTry: 'sudo apt-get install -y libclang-dev && python3 -m pip install clang'", file=sys.stderr)
    sys.exit(3)

# Config
INCLUDE_DIR = 'include'
HEADER_EXTS = ('.hpp', '.h')

ERRORS = []
WARNINGS = []


def find_headers():
    for root, _, files in os.walk(INCLUDE_DIR):
        for f in files:
            if f.endswith(HEADER_EXTS):
                yield os.path.join(root, f)


def mk_temp_wrapper(header_path):
    # Create a tiny TU that includes the header to parse it
    return f'#include "{os.path.relpath(header_path)}"\n'


def parse_wrapper(wrapper_code, args):
    # Create a temporary file and parse it
    with tempfile.NamedTemporaryFile(suffix='.cpp', mode='w', delete=False) as tmp:
        tmp.write(wrapper_code)
        tmp_path = tmp.name
    index = cindex.Index.create()
    try:
        tu = index.parse(tmp_path, args=args)
    except Exception as exc:
        print(f"ERROR: libclang failed to parse {tmp_path}: {exc}", file=sys.stderr)
        os.unlink(tmp_path)
        return None
    os.unlink(tmp_path)
    return tu


def report_loc(cursor):
    loc = cursor.location
    if not loc or not loc.file:
        return '<unknown>'
    return f"{loc.file}:{loc.line}"


def is_noexcept_func(cursor):
    try:
        # Fallback: inspect spelling of source range for 'noexcept'
        extent = cursor.extent
        with open(extent.start.file.name, 'r') as fh:
            lines = fh.readlines()
        func_text = ''.join(lines[extent.start.line-1:extent.end.line])
        if 'noexcept' in func_text:
            return True
    except Exception:
        pass
    return False


def check_cursor(cursor, enabled_checks):
    # Recurse
    for c in cursor.get_children():
        kind = c.kind
        # Virtual methods
        if enabled_checks.get('virtual') and kind == cindex.CursorKind.CXX_METHOD:
            if c.is_virtual_method():
                ERRORS.append((report_loc(c), 'virtual method declared'))
        # dynamic_cast / typeid
        if enabled_checks.get('rtti') and (kind == cindex.CursorKind.CXX_DYNAMIC_CAST_EXPR or kind == cindex.CursorKind.CXX_REINTERPRET_CAST_EXPR):
            ERRORS.append((report_loc(c), 'dynamic_cast or reinterpret_cast used'))
        if enabled_checks.get('rtti') and kind == cindex.CursorKind.TYPEID_EXPR:
            ERRORS.append((report_loc(c), 'typeid used'))
        # throw expressions
        if enabled_checks.get('throw') and kind == cindex.CursorKind.CXX_THROW_EXPR:
            # find enclosing function
            parent = c.semantic_parent
            if parent and parent.kind in (cindex.CursorKind.FUNCTION_DECL, cindex.CursorKind.CXX_METHOD, cindex.CursorKind.FUNCTION_TEMPLATE):
                if is_noexcept_func(parent):
                    WARNINGS.append((report_loc(c), 'throw inside noexcept function'))
                else:
                    WARNINGS.append((report_loc(c), 'throw expression'))
            else:
                WARNINGS.append((report_loc(c), 'throw expression'))
        # new / malloc / free
        if enabled_checks.get('heap') and kind == cindex.CursorKind.CXX_NEW_EXPR:
            WARNINGS.append((report_loc(c), 'operator new used'))
        if enabled_checks.get('heap') and kind == cindex.CursorKind.CALL_EXPR:
            # check callee spelling for malloc/free
            try:
                callee = c.get_definition() or (c.referenced)
                if callee and callee.spelling in ('malloc', 'free'):
                    WARNINGS.append((report_loc(c), f"call to {callee.spelling} detected"))
            except Exception:
                # Fallback: inspect tokens
                toks = list(c.get_tokens())
                if toks:
                    name = toks[0].spelling
                    if name in ('malloc', 'free'):
                        WARNINGS.append((report_loc(c), f"call to {name} detected"))
        # smart pointers
        if enabled_checks.get('smartptr') and kind == cindex.CursorKind.VAR_DECL:
            t = c.type.spelling
            if 'std::unique_ptr' in t or 'std::shared_ptr' in t:
                WARNINGS.append((report_loc(c), f"smart pointer type used: {t}"))
        # Recurse
        check_cursor(c, enabled_checks)



def get_common_args():
    # Basic args so libclang can parse headers; prefer compile_commands if available
    args = ['-std=c++11', '-Iinclude', '-I.']
    # Try to read compile_commands.json for include flags
    cc_path = os.path.join('build', 'compile_commands.json')
    if os.path.exists(cc_path):
        try:
            with open(cc_path) as fh:
                cc = json.load(fh)
            # take flags from first entry
            if cc and isinstance(cc, list):
                cmd = cc[0].get('command') or cc[0].get('arguments')
                if isinstance(cmd, str):
                    tokens = cmd.split()
                else:
                    tokens = cmd
                # keep -I... and -std=..
                for t in tokens:
                    if t.startswith('-I') or t.startswith('-std') or t.startswith('-D'):
                        args.append(t)
        except Exception:
            pass
    return args


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('--compile-commands', default='build/compile_commands.json')
    parser.add_argument('--check-virtual', action='store_true')
    parser.add_argument('--check-rtti', action='store_true')
    parser.add_argument('--check-heap', action='store_true')
    parser.add_argument('--check-smartptr', action='store_true')
    parser.add_argument('--check-throw', action='store_true')
    args = parser.parse_args()

    # If no specific checks requested, run all
    enabled_checks = {
        'virtual': args.check_virtual or not any([args.check_virtual, args.check_rtti, args.check_heap, args.check_smartptr, args.check_throw]),
        'rtti': args.check_rtti or not any([args.check_virtual, args.check_rtti, args.check_heap, args.check_smartptr, args.check_throw]),
        'heap': args.check_heap or not any([args.check_virtual, args.check_rtti, args.check_heap, args.check_smartptr, args.check_throw]),
        'smartptr': args.check_smartptr or not any([args.check_virtual, args.check_rtti, args.check_heap, args.check_smartptr, args.check_throw]),
        'throw': args.check_throw or not any([args.check_virtual, args.check_rtti, args.check_heap, args.check_smartptr, args.check_throw]),
    }

    headers = list(find_headers())
    if not headers:
        print('No headers found to check', file=sys.stderr)
        return 0

    clang_args = get_common_args()

    # Initialize libclang: try to find libclang
    try:
        cindex.Config.set_library_file(cindex.Config.library_file)
    except Exception:
        # ignore; hope libclang is on PATH
        pass

    for h in headers:
        wrapper = mk_temp_wrapper(h)
        tu = parse_wrapper(wrapper, args=clang_args)
        if tu is None:
            print(f'ERROR: failed to parse {h}', file=sys.stderr)
            ERRORS.append((h, 'parse failure'))
            continue
        # Walk the AST
        check_cursor(tu.cursor, enabled_checks)

    # Report
    for loc, msg in ERRORS:
        print(f'ERROR: {loc}: {msg}')
    for loc, msg in WARNINGS:
        print(f'WARNING: {loc}: {msg}')

    if ERRORS:
        return 2
    if WARNINGS:
        return 1
    return 0


if __name__ == '__main__':
    sys.exit(main())
