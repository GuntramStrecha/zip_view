# Architecture Enforcement - Quick Start

This directory contains tools to automatically verify that code changes don't violate architectural rules in the `zip_view` library.

## What's Been Added

### 1. **GitHub Actions Workflow** ✓ (Ready to Use)
**File**: `.github/workflows/architecture.yml`

**What it checks**:
- ✓ C++11 compatibility (strict compile)
- ✓ Header-only constraint verification
- ✓ No C++14+ features detection
- ✓ No virtual functions (zero-cost abstraction)
- ✓ Namespace structure validation
- ✓ Runs architecture validation script
- ✓ Executes architecture test suite
- ✓ Runs clang-tidy architecture checks

**Triggers**:
- Push to `main` or `develop` branches
- Pull requests to `main` or `develop`
- Manual workflow dispatch

**View results**:
- GitHub Actions tab → Architecture workflow
- Badge: Add to README.md if desired

### 2. **Shell Script Validator** ✓ (Ready to Use)
**File**: `scripts/check_architecture.sh`

**Quick Start**:
```bash
./scripts/check_architecture.sh
```

**What it checks**:
- ✓ C++11 compatibility (no C++14+ features)
- ✓ Header-only constraint (no .cpp in include/)
- ✓ No virtual functions (zero-cost abstraction)
- ✓ No dynamic allocation keywords
- ✓ Proper namespace structure
- ✓ No exceptions in noexcept contexts
- ✓ Standard iterator interface
- ✓ No runtime polymorphism (typeid/dynamic_cast)
- ✓ Include guards

**Usage**:
```bash
# Run manually
./scripts/check_architecture.sh

# Add to pre-commit hook
echo "./scripts/check_architecture.sh" >> .git/hooks/pre-commit
chmod +x .git/hooks/pre-commit

# Run in CI (automatically via .github/workflows/architecture.yml)
```

### 3. **clang-tidy Wrapper Script** ✓ (Ready to Use)
**File**: `scripts/run_clang_tidy.sh`

**Quick Start**:
```bash
./scripts/run_clang_tidy.sh
```

**What it does**:
- Runs clang-tidy with proper configuration
- Suppresses GCC-specific warning flags
- Uses the enhanced `.clang-tidy` configuration

**Usage**:
```bash
# Run clang-tidy checks
./scripts/run_clang_tidy.sh

# With additional filters
./scripts/run_clang_tidy.sh --checks='performance-*'
```

### 4. **Compile-Time Tests** ✓ (Ready to Use)
**File**: `tests/architecture.cpp`

**What it tests** (at compile time using `static_assert`):
- View size constraints (no bloat)
- Iterator category computation
- SFINAE-based conditional APIs
- Standard iterator interface requirements
- Copy/move semantics
- Const-correctness (shallow constness)

**Test it**:
```bash
# Compile with C++11 (strict)
g++ -std=c++11 -I include/ tests/architecture.cpp -o /tmp/arch_test

# If it compiles → all tests passed
# If it fails → architecture violation detected
```

**Add to CMake** (optional):
```cmake
add_executable(ArchitectureTests tests/architecture.cpp)
target_compile_features(ArchitectureTests PRIVATE cxx_std_11)
target_compile_options(ArchitectureTests PRIVATE
  $<$<CXX_COMPILER_ID:GNU,Clang>:-std=c++11 -pedantic -Werror>
)
add_test(NAME ArchitectureTests COMMAND ArchitectureTests)
```

### 5. **Enhanced clang-tidy Configuration** ✓ (Ready to Use)
**File**: `.clang-tidy`

**What it enforces**:
- Core C++ guidelines (`cppcoreguidelines-*`)
- Performance checks (`performance-*`)
- Readability rules (`readability-*`)
- Bug-prone patterns (`bugprone-*`)
- Excludes C++14+ modernization warnings

**Usage**: Automatically used by `scripts/run_clang_tidy.sh` and CI

### 6. **Documentation**
- `docs/ARCHITECTURE_TESTING.md` - Comprehensive guide to all approaches
- `ARCHITECTURE.md` - Deep architectural analysis

## Verification Matrix

| Check Type | Location | When to Run | Time |
|------------|----------|-------------|------|
| **GitHub Actions** | `.github/workflows/architecture.yml` | Push/PR to main/develop | ~2min |
| **Shell script** | `scripts/check_architecture.sh` | Pre-commit, CI | ~1s |
| **Compile-time** | `tests/architecture.cpp` | Build time | ~2s |
| **Runtime tests** | `tests/arch.cpp` | CTest | ~1s |
| **clang-tidy** | `scripts/run_clang_tidy.sh` | Manual, CI | ~30s |

## Enforced Architecture Rules

### Critical Rules (Automated)
1. ✓ **C++11 compatibility** - No C++14+ features in `include/`
2. ✓ **Header-only** - No .cpp files in `include/`
3. ✓ **Zero-cost abstraction** - No virtual functions
4. ✓ **No heap allocation** - No new/delete in views
5. ✓ **SFINAE-based API** - No runtime dispatch
6. ✓ **Iterator category** - Correctly computed as weakest
7. ✓ **Const-correctness** - Shallow constness model

### Detected Violations
The tools will catch:
- `std::make_unique` → C++14 violation
- `if constexpr` → C++17 violation
- `virtual` keyword → Zero-cost violation
- `new`/`delete` → Heap allocation violation
- `typeid`/`dynamic_cast` → Runtime polymorphism violation
- Missing iterator typedefs → STL compatibility violation

## Recommended Workflow

### 1. During Development
```bash
# Quick check before commit
./scripts/check_architecture.sh
```

### 2. Before Push
```bash
# Full verification
./scripts/check_architecture.sh
cmake --build build --target ZipViewTests
ctest --test-dir build --output-on-failure
```

### 3. In CI (Automated)
Add to `.github/workflows/ci.yml`:
```yaml
- name: Architecture Validation
  run: ./scripts/check_architecture.sh

- name: Compile-time Architecture Tests
  run: |
    g++ -std=c++11 -pedantic -Werror \
        -I include/ tests/architecture.cpp \
        -o /tmp/arch_test
```

## What Was Not Auto-Enforced (Requires Manual Review)

Some architectural properties can't be automatically checked:
- **Semantic correctness** - Does the code do what it's supposed to?
- **Performance characteristics** - Is it O(1) or O(n)?
- **Documentation accuracy** - Do comments match code?
- **API design** - Is it intuitive and consistent?

These require code review and careful testing.

## Next Steps (Optional Enhancements)

1. **Add to CMake**
   ```cmake
   # Add in tests/CMakeLists.txt
   add_executable(ArchitectureTests architecture.cpp)
   add_test(NAME ArchitectureTests COMMAND ArchitectureTests)
   ```

2. **Integrate with pre-commit**
   ```bash
   # Install pre-commit framework
   pip install pre-commit

   # Add to .pre-commit-config.yaml
   repos:
     - repo: local
       hooks:
         - id: architecture-check
           name: Architecture validation
           entry: ./scripts/check_architecture.sh
           language: system
           pass_filenames: false
   ```

3. **Enhanced clang-tidy**
   - See `docs/ARCHITECTURE_TESTING.md` for detailed configuration

4. **Custom clang-tidy checks**
   - Write project-specific checks for unique architectural constraints

## Testing the Tools

Verify the architecture enforcement tools work:

```bash
# Test 1: Current code should pass
./scripts/check_architecture.sh
# Expected: All checks pass with ✓

# Test 2: Compile-time tests should compile
g++ -std=c++11 -I include/ tests/architecture.cpp -o /tmp/arch_test
# Expected: Compiles successfully

# Test 3: Introduce a violation (for testing)
# Temporarily add "std::make_unique" to include/zip_view.hpp
./scripts/check_architecture.sh
# Expected: ERROR about C++14+ features

# Test 4: Remove the violation
# Remove the test change
./scripts/check_architecture.sh
# Expected: Back to passing
```

## Summary

✓ **Shell script** (`scripts/check_architecture.sh`) - Fast, comprehensive checks
✓ **Compile-time tests** (`tests/architecture.cpp`) - Guarantees via static_assert
✓ **Documentation** (`docs/ARCHITECTURE_TESTING.md`) - Full guide
✓ **All tools tested and working** - Ready for immediate use

**Bottom Line**: Run `./scripts/check_architecture.sh` before every commit to catch architectural violations automatically.
