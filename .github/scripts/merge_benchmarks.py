#!/usr/bin/env python3
"""Merge per-arch Google Benchmark JSON artifacts and produce outputs usable by
`benchmark-action/github-action-benchmark`'s `customSmallerIsBetter` tool.

This script performs three things:
 - Reads per-arch artifacts at `<artifacts-dir>/benchmark-results-<arch>/benchmark_results.json`
 - Writes `benchmark_results_merged.json` which is an array of {name, unit, value}
   suitable for the action when using `tool: 'customSmallerIsBetter'`.

Usage: merge_benchmarks.py --artifacts-dir artifacts --out-dir merged
"""
import argparse
import json
import os
import sys

DEFAULT_ARCHES = ["x86_64", "x86_32", "arm64", "arm32"]


def load_json_if_exists(path):
    if not os.path.exists(path):
        return None
    try:
        with open(path) as f:
            return json.load(f)
    except Exception as e:
        return {"error": f"failed to parse {path}: {e}"}


def create_summary(merged, out_path):
    """Write a concise summary showing one value per `run_name`.

    Prefer the `aggregate` entry named `mean`. If not available, compute the
    mean from `iteration` (repetition) entries.
    """
    lines = []
    lines.append("## Benchmark Results Summary (All Architectures)\n")
    for block in merged:
        arch = block.get("arch")
        results = block.get("results") or {}
        lines.append(f"### {arch}\n")
        benches = results.get("benchmarks") if isinstance(results, dict) else []

        # only accept explicit aggregate-mean entries
        mean_map = {}
        for b in benches:
            run_name = b.get("run_name") or b.get("name")
            if not run_name:
                continue
            if b.get("run_type") == "aggregate" and b.get("aggregate_name") == "mean":
                val = b.get("real_time")
                unit = b.get("time_unit") or b.get("aggregate_unit") or "ns"
                if val is not None:
                    mean_map[run_name] = (val, unit)

        if mean_map:
            lines.append("```text")
            for rn, (t, u) in sorted(mean_map.items()):
                lines.append(f"{rn}: {t} {u}")
            lines.append("```\n")
        else:
            lines.append("No benchmark data found\n")
    with open(out_path, "w") as f:
        f.write("\n".join(lines))


def create_merged_json(merged, out_path):
    """Produce one merged value per `run_name` per architecture.

    - Prefer `aggregate` entries with `aggregate_name == 'mean'`.
    - Fallback: compute mean across `iteration` (repetition) entries.
    """
    out = []
    for entry in merged:
        arch = entry.get("arch")
        results = entry.get("results")
        if not isinstance(results, dict):
            # Missing file or parse error was recorded earlier; skip.
            continue
        benches = results.get("benchmarks") or []
        if not benches:
            # Nothing to consume for this arch
            continue

        # collect only explicit aggregate mean entries
        selected = {}
        for b in benches:
            if not isinstance(b, dict):
                continue
            run_name = b.get("run_name") or b.get("name")
            if not run_name:
                continue
            if b.get("run_type") == "aggregate" and b.get("aggregate_name") == "mean":
                time = b.get("real_time")
                unit = b.get("time_unit") or b.get("aggregate_unit") or "ns"
                if time is not None:
                    selected[run_name] = (time, unit)

        # emit one entry per run_name (only mean entries)
        for rn, (time, unit) in sorted(selected.items()):
            out.append({
                "name": f"{rn} [{arch}]",
                "unit": unit,
                "value": time,
            })
    try:
        with open(out_path, "w") as f:
            json.dump(out, f, indent=2)
    except Exception as e:
        print(f"Failed to write custom output file: {e}", file=sys.stderr)
        sys.exit(3)


def main():
    p = argparse.ArgumentParser()
    p.add_argument("--artifacts-dir", default="artifacts", help="Path where per-arch artifact folders live")
    p.add_argument("--out-dir", default="merged", help="Path where merged outputs are written")
    p.add_argument("--arches", default=','.join(DEFAULT_ARCHES), help="Comma-separated list of architectures to look for")
    args = p.parse_args()

    artifacts_dir = args.artifacts_dir
    out_dir = args.out_dir
    arches = [a.strip() for a in args.arches.split(',') if a.strip()]

    os.makedirs(out_dir, exist_ok=True)

    merged = []

    for arch in arches:
        json_path = os.path.join(artifacts_dir, f"benchmark-results-{arch}", "benchmark_results.json")
        data = load_json_if_exists(json_path)
        entry = {"arch": arch, "results": data}
        merged.append(entry)

    # Create human-readable summary
    summary_path = os.path.join(out_dir, "benchmark_summary.md")
    create_summary(merged, summary_path)

    # Create format for `customSmallerIsBetter`
    merged_path = os.path.join(out_dir, "benchmark_results_merged.json")
    create_merged_json(merged, merged_path)

    # Print results for logs
    print("Wrote:", merged_path)
    print("---\nSummary:\n")
    with open(summary_path) as f:
        print(f.read())


if __name__ == '__main__':
    main()
