file(GLOB_RECURSE ALL_EXAMPLE_SOURCES "${CMAKE_SOURCE_DIR}/examples/*.cpp")

# Add executables
add_executable(ZipViewExample ${ALL_EXAMPLE_SOURCES})

# Set C++ standard for each target
set_target_properties(ZipViewExample PROPERTIES CXX_STANDARD 11)

# Add tests
add_test(NAME ZipViewExample COMMAND ZipViewExample)
