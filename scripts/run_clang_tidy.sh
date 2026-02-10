#!/bin/bash
# Wrapper script to run clang-tidy with proper flags
# Suppresses GCC-specific warnings that clang doesn't understand

set -e

if [ ! -f "build/compile_commands.json" ]; then
  echo "Error: build/compile_commands.json not found"
  echo "Run 'cmake -B build' first to generate compilation database"
  exit 1
fi

# Run clang-tidy with extra args to suppress unknown warning options
# These warnings come from GCC-specific flags in compile_commands.json
clang-tidy -p build include/zip_view.hpp \
  --extra-arg=-Wno-unknown-warning-option \
  "$@"
