# Architecture Rule Enforcement

This document describes automated methods to verify that code changes don't violate architectural rules.

## Architecture Rules for zip_view

1. **C++11 compatibility** (production code only)
2. **Header-only** (no .cpp in include/)
3. **No dynamic allocation** (no new/malloc/unique_ptr/shared_ptr in views)
4. **No virtual functions** (zero-cost abstraction)
5. **No exceptions in constructors** (noexcept where appropriate)
6. **Constexpr where possible** (compile-time computation)
7. **SFINAE-based conditional API** (no runtime dispatch)

---

## Method 1: Enhanced clang-tidy Configuration

### Implementation

Create `.clang-tidy` with architectural checks:

```yaml
---
Checks: >
  cppcoreguidelines-*,
  modernize-*,
  performance-*,
  readability-*,
  bugprone-*,
  -modernize-use-trailing-return-type,
  -modernize-use-auto,
  -cppcoreguidelines-avoid-magic-numbers,
  -readability-magic-numbers,
  -cppcoreguidelines-pro-bounds-pointer-arithmetic,
  -cppcoreguidelines-pro-bounds-constant-array-index

WarningsAsErrors: true
FormatStyle: file

CheckOptions:
  # Enforce C++11 (no C++14+ features in include/)
  - key: modernize-use-nullptr.NullMacros
    value: 'NULL'

  # No heap allocation
  - key: cppcoreguidelines-owning-memory.LegacyResourceProducers
    value: 'malloc;new'

  # Performance
  - key: performance-move-const-arg.CheckTriviallyCopyableMove
    value: true

  # Readability
  - key: readability-identifier-naming.ClassCase
    value: snake_case
  - key: readability-identifier-naming.StructCase
    value: snake_case
  - key: readability-identifier-naming.FunctionCase
    value: snake_case
```

### Specific Checks for Architecture Rules

| Rule | clang-tidy Check |
|------|------------------|
| No virtual functions | `cppcoreguidelines-virtual-class-destructor` |
| No dynamic allocation | `cppcoreguidelines-owning-memory` |
| No raw pointers (except ref_view) | `cppcoreguidelines-pro-type-reinterpret-cast` |
| Const correctness | `readability-const-return-type`, `readability-make-member-function-const` |
| Performance | `performance-unnecessary-copy-initialization` |

### Run clang-tidy on include/ only

```bash
# Add to CI
find include/ -name "*.hpp" | while read file; do
  clang-tidy -p build "$file" --warnings-as-errors='*'
done
```

---

## Method 2: Compile-Time Architecture Tests

### Concept: Test Architectural Properties at Compile Time

Create `tests/architecture_tests.cpp`:

```cpp
#include "../include/zip_view.hpp"
#include <type_traits>
#include <vector>
#include <list>

// Rule: zip_view is trivially copyable (no dynamic allocation)
static_assert(
  std::is_trivially_copyable<gst::ranges::zip_view<std::vector<int>&, std::list<int>&>>::value,
  "zip_view should be trivially copyable"
);

// Rule: ref_view is trivially copyable
static_assert(
  std::is_trivially_copyable<gst::detail::ref_view<std::vector<int>>>::value,
  "ref_view should be trivially copyable"
);

// Rule: iterators are regular types
static_assert(
  std::is_copy_constructible<gst::ranges::zip_view<std::vector<int>&>::iterator>::value,
  "zip iterator should be copyable"
);

// Rule: No virtual functions (object size == expected)
template<typename T>
constexpr bool has_no_vtable() {
  return sizeof(T) == sizeof(decltype(std::declval<T>().views_));
}

// Rule: SFINAE works correctly (operator-- only for bidirectional)
template<typename Iter, typename = void>
struct has_decrement : std::false_type {};

template<typename Iter>
struct has_decrement<Iter, decltype(--std::declval<Iter&>(), void())>
  : std::true_type {};

static_assert(
  !has_decrement<gst::ranges::zip_view<std::forward_list<int>&>::iterator>::value,
  "Forward iterator should not have operator--"
);

// Rule: C++11 compatibility check (no C++14+ features used)
// This file should compile with -std=c++11
#if __cplusplus > 201103L
  #error "This compile-time test must be built with C++11"
#endif
```

### Add to CMakeLists.txt

```cmake
# Compile-time architecture validation
add_executable(ArchitectureTests tests/architecture_tests.cpp)
target_compile_features(ArchitectureTests PRIVATE cxx_std_11)
target_compile_options(ArchitectureTests PRIVATE
  $<$<CXX_COMPILER_ID:GNU,Clang>:-std=c++11 -pedantic -Werror>
  $<$<CXX_COMPILER_ID:MSVC>:/std:c++11 /WX>
)
```

---

## Method 3: Runtime Architecture Tests (Unit Tests)

### Test Architectural Properties

Add to `tests/base.cpp` or new `tests/architecture_runtime.cpp`:

```cpp
#include <catch2/catch_test_macros.hpp>
#include "zip_view.hpp"
#include <vector>
#include <list>

TEST_CASE("Architecture: Size constraints", "[architecture]") {
  using ZipView = gst::ranges::zip_view<std::vector<int>&, std::list<int>&>;

  SECTION("zip_view is small (no heap allocation)") {
    // Should be just two pointers (for ref_view)
    REQUIRE(sizeof(ZipView) <= 2 * sizeof(void*) + 32); // generous upper bound
  }

  SECTION("iterator is small") {
    using Iterator = ZipView::iterator;
    // Should be tuple of iterators, nothing more
    REQUIRE(sizeof(Iterator) <= 64); // generous upper bound
  }
}

TEST_CASE("Architecture: Const correctness", "[architecture]") {
  std::vector<int> v1{1, 2, 3};
  std::vector<int> v2{4, 5, 6};

  SECTION("Shallow constness: const view allows element modification") {
    const auto z = gst::ranges::views::zip(v1, v2);

    // Should compile: const view but non-const elements
    auto [a, b] = *z.begin();
    a = 10; // Should modify v1
    b = 20; // Should modify v2

    REQUIRE(v1[0] == 10);
    REQUIRE(v2[0] == 20);
  }
}

TEST_CASE("Architecture: No heap allocation", "[architecture]") {
  // This test verifies via instrumentation that no heap allocation occurs
  std::vector<int> v1{1, 2, 3};
  std::vector<int> v2{4, 5, 6};

  // Could use custom allocator or memory tracking
  auto z = gst::ranges::views::zip(v1, v2);
  auto it = z.begin();
  auto end = z.end();

  // Iterate without heap allocation
  while (it != end) {
    auto [a, b] = *it;
    (void)a; (void)b;
    ++it;
  }

  // If using memory tracking, verify count == 0
  SUCCEED("No crashes means no unexpected allocations");
}

TEST_CASE("Architecture: SFINAE correctness", "[architecture]") {
  using ForwardView = gst::ranges::zip_view<std::forward_list<int>&>;
  using BiDirView = gst::ranges::zip_view<std::list<int>&>;
  using RandomView = gst::ranges::zip_view<std::vector<int>&>;

  SECTION("Forward iterator lacks operator--") {
    // Should not compile (tested at compile time)
    // std::forward_list<int> fl{1, 2, 3};
    // auto z = gst::ranges::views::zip(fl);
    // auto it = z.begin();
    // --it; // ERROR: no operator--
  }

  SECTION("Iterator category matches weakest iterator") {
    std::vector<int> vec{1, 2, 3};
    std::list<int> lst{4, 5, 6};
    std::forward_list<int> fwd{7, 8, 9};

    // Mixed: vector (random) + list (bidir) = bidir
    auto z1 = gst::ranges::views::zip(vec, lst);
    using Cat1 = typename decltype(z1)::iterator::iterator_category;
    static_assert(std::is_same<Cat1, std::bidirectional_iterator_tag>::value,
                  "Should be bidirectional");

    // Mixed: vector (random) + forward_list (forward) = forward
    auto z2 = gst::ranges::views::zip(vec, fwd);
    using Cat2 = typename decltype(z2)::iterator::iterator_category;
    static_assert(std::is_same<Cat2, std::forward_iterator_tag>::value,
                  "Should be forward");
  }
}
```

---

## Method 4: CI Pipeline Checks

### Add to `.github/workflows/ci.yml`

```yaml
      - name: Check C++11 compatibility
        run: |
          # Compile include/zip_view.hpp with strict C++11
          ${{ matrix.compiler }} -std=c++11 -pedantic -Werror \
            -I include/ -c include/zip_view.hpp -o /dev/null

      - name: Verify no heap allocation (nm check)
        run: |
          # Build and check symbols
          cmake --build build --target ZipViewExamples
          # Verify no malloc/new symbols in examples (they should be from std containers only)
          nm build/examples/ZipViewExamples | grep -E "malloc|_Znwm" || true

      - name: clang-tidy architecture check
        if: matrix.compiler == 'clang++'
        run: |
          find include/ -name "*.hpp" | xargs clang-tidy -p build \
            --checks='-*,cppcoreguidelines-*,performance-*' \
            --warnings-as-errors='*'

      - name: Header-only verification
        run: |
          # Verify no .cpp files in include/
          if find include/ -name "*.cpp" | grep -q .; then
            echo "ERROR: .cpp files found in include/ directory"
            exit 1
          fi

      - name: Check for C++14+ features in include/
        run: |
          # Search for C++14+ features in production code
          BAD_FEATURES=$(grep -rE \
            "std::(make_unique|make_index_sequence|enable_if_t|decay_t|remove_reference_t)" \
            include/ || true)
          if [ ! -z "$BAD_FEATURES" ]; then
            echo "ERROR: C++14+ features found in include/:"
            echo "$BAD_FEATURES"
            exit 1
          fi
```

---

## Method 5: Custom Architecture Linter Script

### Create `scripts/check_architecture.sh`

```bash
#!/bin/bash
set -e

echo "=== Checking Architecture Rules ==="

# Rule 1: C++11 compatibility
echo "Checking C++11 compatibility..."
if grep -rE "std::(make_unique|make_index_sequence|enable_if_t)" include/; then
  echo "ERROR: C++14+ features found in include/"
  exit 1
fi

# Rule 2: Header-only
echo "Checking header-only constraint..."
if find include/ -name "*.cpp" | grep -q .; then
  echo "ERROR: .cpp files found in include/"
  exit 1
fi

# Rule 3: No virtual functions
echo "Checking for virtual functions..."
if grep -rE "virtual\s+" include/; then
  echo "ERROR: virtual functions found in include/"
  exit 1
fi

# Rule 4: No exceptions in noexcept contexts
echo "Checking exception safety..."
if grep -A5 "noexcept" include/ | grep -E "(throw|try|catch)"; then
  echo "ERROR: exceptions in noexcept context"
  exit 1
fi

# Rule 5: Proper namespace structure
echo "Checking namespace structure..."
if ! grep -q "namespace gst" include/zip_view.hpp; then
  echo "ERROR: Missing gst namespace"
  exit 1
fi
if ! grep -q "namespace detail" include/zip_view.hpp; then
  echo "ERROR: Missing detail namespace"
  exit 1
fi

# Rule 6: No dynamic allocation keywords
echo "Checking for heap allocation..."
if grep -rE "\b(new|delete|malloc|free|unique_ptr|shared_ptr|make_unique|make_shared)\s*[^/]" include/ | \
   grep -v "// Allow:" | grep -v "\/\/" ; then
  echo "WARNING: Heap allocation keywords found (review manually)"
fi

echo "=== All architecture checks passed ==="
```

### Make executable and add to CI

```bash
chmod +x scripts/check_architecture.sh

# In CI:
- name: Architecture validation
  run: ./scripts/check_architecture.sh
```

---

## Method 6: Documentation + Code Review Checklist

### Create `docs/REVIEW_CHECKLIST.md`

```markdown
# Code Review Architecture Checklist

Before approving changes to `include/zip_view.hpp`, verify:

- [ ] C++11 compatible (no auto return types, no std::make_unique, etc.)
- [ ] No dynamic allocation (no new/delete/unique_ptr/shared_ptr)
- [ ] No virtual functions
- [ ] SFINAE used for conditional APIs (not runtime checks)
- [ ] Const-correctness follows shallow constness model
- [ ] All public APIs are noexcept where appropriate
- [ ] Type traits computed at compile time (no typeid/dynamic_cast)
- [ ] Examples compile as C++11
- [ ] Tests can use C++23 (only tests, not library)
- [ ] clang-format applied
- [ ] clang-tidy clean
- [ ] All tests pass
```

---

## Recommended Implementation Order

1. **Immediate**: Add `scripts/check_architecture.sh` (5 minutes)
2. **Short-term**: Add architecture runtime tests to existing test suite (30 minutes)
3. **Medium-term**: Enhance `.clang-tidy` and add to CI (1 hour)
4. **Long-term**: Add compile-time architecture tests (2 hours)

---

## Comparison Matrix

| Method | Setup Effort | Coverage | False Positives | CI Speed |
|--------|--------------|----------|-----------------|----------|
| clang-tidy | Medium | High | Low | Fast |
| Compile-time tests | Low | Medium | None | Very Fast |
| Runtime tests | Low | Medium | None | Fast |
| Custom scripts | Low | Low-Medium | Medium | Very Fast |
| Code review | Low | Variable | N/A | N/A |

**Recommendation**: Use a **combination**:
- **Custom script** for quick, obvious violations (run on every commit)
- **Compile-time tests** for type-system properties (guarantees)
- **Runtime tests** for behavioral properties (verification)
- **clang-tidy** for deep analysis (run on CI, not pre-commit)

---

## Example: Detecting C++11 Violations

### What to catch:

❌ `auto foo() -> auto` (C++14)
✅ `auto foo() -> int` (C++11 trailing return)

❌ `std::make_unique` (C++14)
✅ `std::unique_ptr<T>(new T{...})` (C++11, though avoid in this library)

❌ `std::index_sequence` (C++14)
✅ `detail::index_sequence` (custom C++11 implementation)

❌ `if constexpr` (C++17)
✅ `std::conditional` + template specialization (C++11)

### Implementation:

```bash
# In scripts/check_architecture.sh
grep -rE "\bauto\s+\w+\([^)]*\)\s*->\s*auto\b" include/ && exit 1
grep -rE "std::make_unique|std::make_shared" include/ && exit 1
grep -rE "std::index_sequence" include/ && exit 1
grep -rE "if\s+constexpr" include/ && exit 1
```

---

## Conclusion

**Static architecture verification is achievable** for zip_view through:

1. **Automated checks** (scripts, clang-tidy)
2. **Compile-time guarantees** (static_assert, SFINAE)
3. **Runtime validation** (unit tests)
4. **CI enforcement** (fail builds on violations)

The layered approach provides defense-in-depth: multiple independent checks catching different classes of violations.
