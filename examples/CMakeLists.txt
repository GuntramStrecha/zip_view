file(GLOB_RECURSE ALL_EXAMPLE_SOURCES "${CMAKE_SOURCE_DIR}/examples/*.cpp")

# Add executables
add_executable(ZipViewExamples ${ALL_EXAMPLE_SOURCES})

# Set C++ standard for each target
set_target_properties(ZipViewExamples PROPERTIES CXX_STANDARD 11
                                                 CXX_STANDARD_REQUIRED YES
                                                 CXX_EXTENSIONS NO)
