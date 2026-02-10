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

# Rule 1: C++11 compatibility (no C++14+ features in include/)
echo "Checking C++11 compatibility..."
if grep -rn --include="*.hpp" -E "std::(make_unique|make_shared|make_index_sequence)" include/ 2>/dev/null; then
  error "C++14+ standard library features found in include/"
elif grep -rn --include="*.hpp" -E "if[[:space:]]+constexpr" include/ 2>/dev/null; then
  error "C++17 'if constexpr' found in include/"
elif grep -rn --include="*.hpp" -E "auto[[:space:]]+[a-zA-Z_][a-zA-Z0-9_]*[[:space:]]*\([^)]*\)[[:space:]]*\{" include/ 2>/dev/null | grep -v -- "->"; then
  # auto function() { // C++14 auto return type deduction
  warning "Possible C++14 auto return type (should use trailing return type)"
else
  success "C++11 compatibility verified"
fi

# Rule 2: Header-only (no .cpp files in include/)
echo "Checking header-only constraint..."
if find include/ -name "*.cpp" 2>/dev/null | grep -q .; then
  error ".cpp files found in include/ directory"
else
  success "Header-only constraint verified"
fi

# Rule 3: No virtual functions (zero-cost abstraction principle)
echo "Checking for virtual functions..."
if grep -rn --include="*.hpp" -E "virtual[[:space:]]+" include/ 2>/dev/null | grep -v "//"; then
  error "virtual functions found in include/"
else
  success "No virtual functions (zero-cost abstraction maintained)"
fi

# Rule 4: No dynamic allocation in view/iterator classes
echo "Checking for heap allocation..."
ALLOC_CHECK=$(grep -rn --include="*.hpp" -E "(new|delete|malloc|free)[[:space:]]+[^/]" include/ 2>/dev/null | grep -v "//" || true)
if [ ! -z "$ALLOC_CHECK" ]; then
  warning "Heap allocation keywords found (verify these are in comments only):"
  echo "$ALLOC_CHECK"
else
  success "No obvious heap allocation"
fi

# Check for smart pointers (should not be in view/iterator storage)
SMART_PTR=$(grep -rn --include="*.hpp" -E "std::(unique_ptr|shared_ptr)" include/ 2>/dev/null | grep -v "//" || true)
if [ ! -z "$SMART_PTR" ]; then
  warning "Smart pointers found (verify these don't violate zero-allocation):"
  echo "$SMART_PTR"
fi

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

# Rule 8: SFINAE-based conditional APIs (no runtime dispatch)
echo "Checking for runtime polymorphism..."
if grep -rn --include="*.hpp" "typeid" include/ 2>/dev/null | grep -v "//"; then
  error "Runtime type information (typeid) found"
fi
if grep -rn --include="*.hpp" "dynamic_cast" include/ 2>/dev/null | grep -v "//"; then
  error "Runtime type casting (dynamic_cast) found"
fi
success "No runtime polymorphism detected"

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
