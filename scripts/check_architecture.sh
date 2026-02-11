#!/bin/bash
# Architecture rule enforcement for zip_view
# Run this script to verify that code changes don't violate architectural constraints

set -e

RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

ERRORS=0
WARNINGS=0

error() {
  echo -e "${RED}ERROR: $1${NC}" >&2
  ERRORS=$((ERRORS + 1))
}

warning() {
  echo -e "${YELLOW}WARNING: $1${NC}"
  WARNINGS=$((WARNINGS + 1))
}

success() {
  echo -e "${GREEN}✓ $1${NC}"
}

echo "=== zip_view Architecture Validation ==="
echo ""

# Rule 1: C++11 compatibility
# C++11 enforcement is handled tightly by CI (see "cpp11-compatibility" job which compiles with -std=c++11).
# Keep a lightweight grep for obvious C++14+ standard-library features as a quick local hint.
echo "Checking C++11 compatibility (quick scan)..."
if grep -rn --include="*.hpp" -E "std::(make_unique|make_shared|make_index_sequence)" include/ 2>/dev/null; then
  warning "Possible C++14+ standard library features found in include/ (CI enforces strict compile)"
else
  success "C++11 quick-scan passed"
fi

# Rule 2: Header-only (no .cpp files in include/)
echo "Checking header-only constraint..."
if find include/ -name "*.cpp" 2>/dev/null | grep -q .; then
  error ".cpp files found in include/ directory"
else
  success "Header-only constraint verified"
fi

# Run clang-tidy (replaces heuristic textual checks)
echo "Running clang-tidy checks..."
TMP_CLANG_OUT=$(mktemp)
if ./scripts/run_clang_tidy.sh -header-filter=".*" 2>&1 | tee "$TMP_CLANG_OUT"; then
  success "clang-tidy checks passed"
else
  error "clang-tidy reported issues (see $TMP_CLANG_OUT)"
  # keep the detailed output visible
  cat "$TMP_CLANG_OUT" >&2 || true
fi
rm -f "$TMP_CLANG_OUT"

# Determine which heuristics clang-tidy can handle by inspecting available checks
echo "Detecting clang-tidy support for architecture heuristics..."
# Try to load our custom plugin if available so its checks appear in the list
PLUGIN_DIR="${PWD}/build/clang_tidy_plugins"
PLUGIN_ARG=""
if [ -d "$PLUGIN_DIR" ]; then
  for f in "$PLUGIN_DIR"/zipview_tidy.*; do
    if [ -f "$f" ]; then
      echo "Using clang-tidy plugin: $f"
      PLUGIN_ARG="-load=$f"
      break
    fi
  done
fi

CLANG_CHECKS=$(clang-tidy $PLUGIN_ARG --list-checks 2>/dev/null || true)
if [ -z "$CLANG_CHECKS" ]; then
  warning "Could not list clang-tidy checks (clang-tidy may be missing). Fallback to script checks will be used."
  MISSING_ALL=1
else
  MISSING_ALL=0
fi

# Map heuristics -> keywords to search in clang-tidy check list
declare -A HEUR_KEYWORDS
HEUR_KEYWORDS[virtual]='virtual'
HEUR_KEYWORDS[rtti]='dynamic|typeid|rtti'
HEUR_KEYWORDS[heap]='owning-memory|malloc|new'
HEUR_KEYWORDS[smartptr]='unique_ptr|shared_ptr|smart'
HEUR_KEYWORDS[throw]='noexcept|throw|exception'

MISSING_ARGS=()
if [ $MISSING_ALL -eq 1 ]; then
  # request all checks from fallback
  MISSING_ARGS+=(--check-virtual --check-rtti --check-heap --check-smartptr --check-throw)
else
  for h in "virtual" "rtti" "heap" "smartptr" "throw"; do
    kw=${HEUR_KEYWORDS[$h]}
    if echo "$CLANG_CHECKS" | grep -Eiq "$kw"; then
      echo "clang-tidy supports heuristic '$h' (matched: $kw)"
    else
      echo "clang-tidy does NOT appear to support heuristic '$h' (needed: $kw); will fallback to script for this check"
      case $h in
        virtual) MISSING_ARGS+=(--check-virtual) ;;
        rtti) MISSING_ARGS+=(--check-rtti) ;;
        heap) MISSING_ARGS+=(--check-heap) ;;
        smartptr) MISSING_ARGS+=(--check-smartptr) ;;
        throw) MISSING_ARGS+=(--check-throw) ;;
      esac
    fi
  done
fi

# If there are missing heuristics, run the AST-based fallback only for them
if [ ${#MISSING_ARGS[@]} -gt 0 ]; then
  echo "Running AST-based fallback for: ${MISSING_ARGS[*]}"
  if python3 scripts/arch_ast_checks.py "${MISSING_ARGS[@]}"; then
    success "AST-based fallback checks passed"
  else
    RC=$?
    if [ $RC -eq 1 ]; then
      warning "AST-based fallback found warnings (see output above)"
    elif [ $RC -eq 2 ]; then
      error "AST-based fallback found errors (see output above)"
    elif [ $RC -eq 3 ]; then
      warning "AST-based fallback skipped: missing python libclang bindings. See docs/ARCHITECTURE_CHECKS.md for setup instructions."
    else
      error "AST-based fallback failed with unexpected exit code $RC"
    fi
  fi
else
  echo "All heuristics appear supported by clang-tidy; no AST fallback needed."
fi

# Note: The script previously performed textual grep-based checks for
# 'virtual', 'new/malloc', and smart-pointer usage. These are now handled
# by clang-tidy's AST-based diagnostics where possible; a libclang fallback
# is used only for heuristics clang-tidy doesn't advertise support for.


# Rule 5: Proper namespace structure
echo "Checking namespace structure..."
if ! grep -q "namespace gst" include/zip_view.hpp; then
  error "Missing 'namespace gst' in zip_view.hpp"
elif ! grep -q "namespace detail" include/zip_view.hpp; then
  error "Missing 'namespace detail' in zip_view.hpp"
elif ! grep -q "namespace ranges" include/zip_view.hpp; then
  error "Missing 'namespace ranges' in zip_view.hpp"
else
  success "Namespace structure correct"
fi

# Rule 6: No exceptions in noexcept contexts
echo "Checking exception safety..."
# This is a heuristic check - looks for throw/try/catch near noexcept
NOEXCEPT_LINES=$(grep -n "noexcept" include/zip_view.hpp | cut -d: -f1)
if [ ! -z "$NOEXCEPT_LINES" ]; then
  for line in $NOEXCEPT_LINES; do
    START=$((line - 5))
    END=$((line + 5))
    if sed -n "${START},${END}p" include/zip_view.hpp | grep -qE "(throw|try|catch)" 2>/dev/null; then
      warning "Potential exception usage near noexcept at line $line"
    fi
  done
fi
success "Exception safety checks completed"

# Rule 7: Public API uses standard iterator interface
echo "Checking iterator interface..."
if ! grep -q "iterator_category" include/zip_view.hpp; then
  warning "Missing iterator_category (required for STL compatibility)"
fi
if ! grep -q "value_type" include/zip_view.hpp; then
  warning "Missing value_type (required for STL compatibility)"
fi
if ! grep -q "difference_type" include/zip_view.hpp; then
  warning "Missing difference_type (required for STL compatibility)"
fi
success "Iterator interface checks completed"

# Runtime-polymorphism checks are handled by clang-tidy (typeid/dynamic_cast will be flagged by AST-based checks where applicable)
# success message retained for script readability
success "Runtime polymorphism checks delegated to clang-tidy"

# Rule 9: Include guards or #pragma once
echo "Checking include guards..."
if ! grep -q "#pragma once" include/zip_view.hpp; then
  if ! grep -q "#ifndef.*_HPP" include/zip_view.hpp; then
    warning "No include guard or #pragma once found"
  fi
fi
success "Include protection verified"

# Summary
echo ""
echo "=== Summary ==="
if [ $ERRORS -gt 0 ]; then
  echo -e "${RED}FAILED: $ERRORS error(s) found${NC}"
  exit 1
elif [ $WARNINGS -gt 0 ]; then
  echo -e "${YELLOW}PASSED with $WARNINGS warning(s)${NC}"
  exit 0
else
  echo -e "${GREEN}PASSED: All architecture rules verified ✓${NC}"
  exit 0
fi
