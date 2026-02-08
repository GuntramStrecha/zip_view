#!/usr/bin/env python3
"""Merge per-arch Google Benchmark JSON artifacts into a single JSON and create a simple markdown summary.

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
    lines = []
    lines.append("## Benchmark Results Summary (All Architectures)\n")
    for block in merged:
        arch = block.get("arch")
        results = block.get("results") or {}
        lines.append(f"### {arch}\n")
        benches = results.get("benchmarks") if isinstance(results, dict) else []
        if benches:
            lines.append("```text")
            for b in benches:
                name = b.get("name")
                time = b.get("real_time")
                unit = b.get("time_unit")
                lines.append(f"{name}: {time} {unit}")
            lines.append("```\n")
        else:
            lines.append("No benchmark data found\n")
    with open(out_path, "w") as f:
        f.write("\n".join(lines))


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
    console_lines = []

    for arch in arches:
        json_path = os.path.join(artifacts_dir, f"benchmark-results-{arch}", "benchmark_results.json")

        data = load_json_if_exists(json_path)
        entry = {"arch": arch, "results": data}
        merged.append(entry)

    merged_json_path = os.path.join(out_dir, "benchmark_results_merged.json")
    with open(merged_json_path, "w") as f:
        json.dump(merged, f, indent=2)

    # Create human-readable summary
    summary_path = os.path.join(out_dir, "benchmark_summary.md")
    create_summary(merged, summary_path)

    # Print results for logs
    print("Wrote:", merged_json_path)
    print("---\nSummary:\n")
    with open(summary_path) as f:
        print(f.read())


if __name__ == '__main__':
    main()
