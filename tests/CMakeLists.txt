# Use C++23 for tests and Catch2
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Fetch Catch2 if not already available
if(NOT TARGET Catch2::Catch2WithMain)
  FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG v3.12.0
  )
  FetchContent_MakeAvailable(Catch2)
endif()

file(GLOB_RECURSE ALL_TEST_SOURCES "${CMAKE_SOURCE_DIR}/tests/*.cpp")

# Add executables
add_executable(ZipViewTests ${ALL_TEST_SOURCES})

# Compile options
target_compile_options(ZipViewTests PRIVATE ${PROJECT_COMPILE_OPTIONS})

# Link libraries
target_link_libraries(ZipViewTests PRIVATE Catch2::Catch2WithMain)

# Add tests
add_test(NAME ZipViewTests COMMAND ZipViewTests)

# Add coverage flags only for ZipViewTests
if(CODE_COVERAGE)
  target_compile_options(ZipViewTests PRIVATE --coverage -O0 -g)
  target_link_options(ZipViewTests PRIVATE --coverage)
endif()
