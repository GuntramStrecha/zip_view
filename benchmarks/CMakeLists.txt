file(GLOB_RECURSE ALL_BENCH_SOURCES "${CMAKE_SOURCE_DIR}/benchmarks/*.cpp")

# Add executables
add_executable(ZipViewBenchmark ${ALL_BENCH_SOURCES})

# Set C++ standard for each target
set_target_properties(ZipViewBenchmark PROPERTIES CXX_STANDARD 23)

# Link libraries
target_link_libraries(ZipViewBenchmark PRIVATE Catch2::Catch2WithMain)
