# Architecture checks

This project uses a combination of `clang-tidy` (AST-based linter) and a small libclang-based checker to enforce repository architecture rules.

What runs in CI
- `clang-tidy` runs with checks configured in `.clang-tidy` and is executed from `scripts/run_clang_tidy.sh`.
- `scripts/check_architecture.sh` orchestrates the checks and also runs `scripts/arch_ast_checks.py` for additional AST checks.

Local setup
- Ensure a CMake build with `compile_commands.json` is available:
  - `cmake -B build -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -S .`
- Install `clang-tidy` and `libclang` development libraries on Debian/Ubuntu:
  - `sudo apt-get update && sudo apt-get install -y clang-tidy libclang-dev`
- Install Python bindings for libclang (via pip):
  - `python3 -m pip install --upgrade pip && python3 -m pip install clang`

Notes
- If Python/`libclang` is not available, the AST checks will fail. CI installs the needed dependencies before running checks.
- If you'd like to add more project-specific rules, we recommend adding a custom clang-tidy check (C++) or enhancing `scripts/arch_ast_checks.py`.

Building the custom clang-tidy checks (optional)
- Configure with the custom checks enabled:
  - `cmake -B build -DBUILD_CLANG_TIDY_CHECKS=ON -S .`
- Build the plugin:
  - `cmake --build build --target zipview_tidy`
- The built plugin will be placed in `build/clang_tidy_plugins/` and is automatically loaded by `scripts/run_clang_tidy.sh` when present.
