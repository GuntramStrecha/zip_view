# Use C++23 for benchmarks and Google Benchmark
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Fetch Google Benchmark if not already available
if(NOT TARGET benchmark::benchmark)
  FetchContent_Declare(
    benchmark
    GIT_REPOSITORY https://github.com/google/benchmark.git
    GIT_TAG v1.9.1
  )
  set(BENCHMARK_ENABLE_TESTING OFF CACHE BOOL "" FORCE)
  set(BENCHMARK_ENABLE_GTEST_TESTS OFF CACHE BOOL "" FORCE)
  set(HAVE_STD_REGEX ON CACHE BOOL "" FORCE)
  set(RUN_HAVE_STD_REGEX 0 CACHE STRING "" FORCE)
  FetchContent_MakeAvailable(benchmark)
endif()

file(GLOB_RECURSE ALL_BENCH_SOURCES "${CMAKE_SOURCE_DIR}/benchmarks/*.cpp")

# Add executables
add_executable(ZipViewBenchmark ${ALL_BENCH_SOURCES})

# Apply project warning flags to our benchmark code, but exclude some that conflict with Google Benchmark
target_compile_options(ZipViewBenchmark PRIVATE ${PROJECT_COMPILE_OPTIONS})
if (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
  # Disable specific warnings that Google Benchmark triggers
  target_compile_options(ZipViewBenchmark PRIVATE
    -Wno-global-constructors
    -Wno-weak-vtables
    -Wno-exit-time-destructors
    -Wno-switch-default
  )
endif()

# Link libraries
target_link_libraries(ZipViewBenchmark PRIVATE benchmark::benchmark benchmark::benchmark_main)
