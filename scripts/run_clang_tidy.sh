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
# Run against all headers in `include/` so new headers get checked automatically.
FILES=$(find include -name "*.hpp" -print)
if [ -z "$FILES" ]; then
  echo "No headers found under include/"
  exit 0
fi

# Attempt to load custom plugin if built
PLUGIN_DIR="${PWD}/build/clang_tidy_plugins"
PLUGIN_ARG=""
if [ -d "$PLUGIN_DIR" ]; then
  for f in "$PLUGIN_DIR"/zipview_tidy.*; do
    if [ -f "$f" ]; then
      echo "Loading clang-tidy plugin: $f"
      PLUGIN_ARG="-load=$f"
      break
    fi
  done
fi

# Execute clang-tidy across all found header files
clang-tidy -p build $PLUGIN_ARG $FILES \
  --header-filter=.* \
  --extra-arg=-Wno-unknown-warning-option \
  "$@"
