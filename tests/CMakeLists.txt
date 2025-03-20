file(GLOB_RECURSE ALL_TEST_SOURCES "${CMAKE_SOURCE_DIR}/tests/*.cpp")

# Add executables
add_executable(ZipViewTests ${ALL_TEST_SOURCES})

# Set C++ standard for each target
set_target_properties(ZipViewTests PROPERTIES CXX_STANDARD 23)

# Link libraries
target_link_libraries(ZipViewTests PRIVATE Catch2::Catch2WithMain)

# Add tests
add_test(NAME ZipViewTests COMMAND ZipViewTests)

# Add coverage flags only for ZipViewTests
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
  option(CODE_COVERAGE "Enable coverage reporting" ON)
  if(CODE_COVERAGE)
    target_compile_options(ZipViewTests PRIVATE --coverage -O0 -g)
    target_link_options(ZipViewTests PRIVATE --coverage)
  endif()
endif()
