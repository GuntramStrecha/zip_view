# Copilot instructions for `zip_view`

`zip_view` is a small, header-only C++ library providing a C++11 implementation of `std::ranges::zip_view` and `std::ranges::views::zip`.

## Build / test / lint

### Configure + build (CMake)

```bash
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build
```

Notes:
- The library itself is header-only (`include/zip_view.hpp`); CMake primarily builds **tests**, **examples**, and **benchmarks**.
- Examples are compiled as **C++11**; tests/benchmarks require a **C++23** compiler.

### Run tests (CTest + Catch2)

```bash
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
cmake --build build --target ZipViewTests
ctest --test-dir build --output-on-failure
```

Run just the test executable via CTest:

```bash
ctest --test-dir build -R ZipViewTests --output-on-failure
```

Run a single Catch2 test scenario (filter by name or tag):

```bash
./build/tests/ZipViewTests "zip_view iterator category*"
./build/tests/ZipViewTests "[temporaries]"
./build/tests/ZipViewTests "[algorithms]"
```

### Run benchmarks

Benchmarks should be built/run from a **Release** build (results are sensitive to optimization level):

```bash
cmake -S . -B build-release -DCMAKE_BUILD_TYPE=Release
cmake --build build-release --target ZipViewBenchmark
./build-release/benchmarks/ZipViewBenchmark
```

CI runs benchmarks with an explicit reporter:

```bash
./build-release/benchmarks/ZipViewBenchmark --reporter console::out=-::colour-mode=none
```

### Formatting / linting

`clang-format` is the primary enforced style:

```bash
cmake --build build --target clang-format
```

There is also a `pre-commit` config that runs `clang-format` on `*.cpp`/`*.hpp`:

```bash
pre-commit run -a
```

`clang-tidy` is configured via `.clang-tidy` but is not wired as a CMake target; run it manually using `compile_commands.json`:

```bash
cmake -S . -B build -DCMAKE_EXPORT_COMPILE_COMMANDS=ON
clang-tidy -p build path/to/file.cpp
```

### Coverage / sanitizers

- Coverage is enabled for `ZipViewTests` on GCC/Clang via the `CODE_COVERAGE` option (default ON in `tests/CMakeLists.txt`). Disable it if you want a “normal” build:

```bash
cmake -S . -B build -DCODE_COVERAGE=OFF
```

- If `gcovr` is installed, a `coverage` target may be available:

```bash
cmake --build build --target coverage
# output: build/coverage.html
```

- Sanitizers can be enabled (GCC/Clang):

```bash
cmake -S . -B build -DENABLE_SANITIZERS=ON
```

## High-level architecture (big picture)

### Header-only core

All implementation lives in **`include/zip_view.hpp`**:
- Public types/functions:
  - `gst::ranges::zip_view<Containers...>`
  - `gst::ranges::views::zip(...)` (factory returning a `zip_view`)
- Support utilities live in `gst::detail` (custom index sequence for C++11, iterator-category meta, etc.).

### Ownership model (lvalues vs temporaries)

`zip_view` stores its inputs in a `std::tuple` using:
- `detail::store_t<T>` which keeps **lvalue references** as references, but **decays and stores rvalues by value**.

This is what makes `gst::ranges::views::zip(...)` safe to use with temporaries (tests cover this heavily).

### Zipping semantics

- `size()` is computed as the **minimum** of the underlying container distances.
- `end()` is computed as `begin()` advanced by that minimum distance for each range.
- Net effect: iteration stops at the **shortest** underlying range (matching `std::ranges::zip_view`).

### Iterator design

- `basic_iterator` holds a tuple of underlying iterators.
- Iterator category is computed at compile time (`detail::zip_iterator_category`) as the **weakest** of the underlying iterator categories.
- Random-access operations (`+`, `-`, `[]`, ordering) are enabled only when the computed category is random-access.
- `operator*()` returns a tuple of references via `std::tie(*it0, *it1, ...)`.
- A custom `iter_swap` swaps element-wise across the zipped tuple to support algorithms like `std::sort` when random-access.

## Repo-specific conventions

- Keep the library implementation **C++11-compatible** (custom `index_sequence` is used instead of `std::index_sequence`). Tests and benchmarks may use C++23 features.
- CI uses very strict warnings with **warnings-as-errors** (`-Werror` on GCC/Clang, `/WX` on MSVC). Changes should be warning-clean across all three.
- Formatting is expected to match `.clang-format` (notably: 2-space indentation and heavy alignment). Prefer running `cmake --build build --target clang-format` (or `pre-commit run -a`) before pushing.
- Tests are Catch2 v3 using `SCENARIO`/`GIVEN`/`WHEN`/`THEN` with tag strings like `"[temporaries]"`, `"[algorithms]"`, etc.; add new tests under `tests/*.cpp` and keep them tag-filterable.
- Tests follow the single responsibility principle strictly. Ensure each test verifies exactly one specific behavior, improving clarity, maintainability, and debugging efficiency.
- Benchmarks are Catch2 benchmarks embedded in `TEST_CASE(...)` blocks; add new benchmarks under `benchmarks/*.cpp`.

## MCP server usage (GitHub)

This repo already works well with the GitHub MCP server for:
- Listing recent workflow runs / digging into failed jobs (CI, benchmarks, CodeQL)
- Pull request review context (files, diffs, comments)

Examples (copy/paste and replace placeholders). For this repo: `owner="GuntramStrecha"`, `repo="zip_view"`.

- List workflows:
  - `github-mcp-server-actions_list { method: "list_workflows", owner: "<owner>", repo: "<repo>" }`

- List recent workflow runs (optionally filter by branch/event/status):
  - `github-mcp-server-actions_list { method: "list_workflow_runs", owner: "<owner>", repo: "<repo>", per_page: 5 }`

- List jobs for a run:
  - `github-mcp-server-actions_list { method: "list_workflow_jobs", owner: "<owner>", repo: "<repo>", resource_id: "<run_id>" }`

- Fetch logs for a specific job (handy when CI fails):
  - `github-mcp-server-get_job_logs { owner: "<owner>", repo: "<repo>", job_id: <job_id>, failed_only: false, return_content: true }`

- Inspect PR details / changed files / diff:
  - `github-mcp-server-pull_request_read { method: "get", owner: "<owner>", repo: "<repo>", pullNumber: <pr_number> }`
  - `github-mcp-server-pull_request_read { method: "get_files", owner: "<owner>", repo: "<repo>", pullNumber: <pr_number>, perPage: 100 }`
  - `github-mcp-server-pull_request_read { method: "get_diff", owner: "<owner>", repo: "<repo>", pullNumber: <pr_number> }`
