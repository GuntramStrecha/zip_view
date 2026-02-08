cmake_minimum_required(VERSION 3.17)

project(ZipViews LANGUAGES CXX VERSION 0.0.1)

enable_testing()

include(FetchContent)
include(CTest)

# Find clang-tidy and clang-format
find_program(CLANG_TIDY_EXE NAMES clang-tidy)
find_program(CLANG_FORMAT_EXE NAMES clang-format)

# Set variables
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_VERBOSE_MAKEFILE ON)

if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
	set(PROJECT_COMPILE_OPTIONS -pedantic -Werror -Wall -Wextra -Wconversion -Wshadow -Wunused -Woverloaded-virtual -Wnon-virtual-dtor -Wold-style-cast -Wduplicated-cond -Wduplicated-branches -Wlogical-op -Wnull-dereference -Wuseless-cast -Wdouble-promotion)
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
  set(PROJECT_COMPILE_OPTIONS -Werror -Weverything -Wno-c++98-compat -Wno-c++98-compat-pedantic -Wno-c++-compat -Wno-padded)
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
  set(PROJECT_COMPILE_OPTIONS /W4 /WX)
endif()

# Include directories
include_directories(${CMAKE_SOURCE_DIR}/include)

# Add subdirectories
add_subdirectory(tests)
add_subdirectory(examples)
add_subdirectory(benchmarks)

# Add clang-format target
if(CLANG_FORMAT_EXE)
  file(GLOB_RECURSE ALL_CXX_SOURCE_FILES
    "${CMAKE_SOURCE_DIR}/include/*.hpp"
    "${CMAKE_SOURCE_DIR}/examples/*.cpp"
    "${CMAKE_SOURCE_DIR}/tests/*.cpp"
    "${CMAKE_SOURCE_DIR}/benchmarks/*.cpp"
  )
  add_custom_target(
    clang-format
    COMMAND ${CLANG_FORMAT_EXE} -i ${ALL_CXX_SOURCE_FILES}
    COMMENT "Running clang-format on source files"
  )
endif()

if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    option(ENABLE_SANITIZERS "Enable sanitizers" OFF)
    if(ENABLE_SANITIZERS)
        add_compile_options(-fsanitize=address,undefined)
    endif()
endif()

# Code coverage option (disabled by default)
option(CODE_COVERAGE "Enable code coverage" OFF)

# Add gcovr target
if(CODE_COVERAGE)
  find_program(GCOVR_EXE NAMES gcovr)
  if(GCOVR_EXE)
    # Common gcovr args
    set(GCOVR_FILTER_ARGS --filter ${CMAKE_SOURCE_DIR}/include/ --exclude-throw-branches)
    set(GCOVR_GCOV_OPTION "")

    # For Clang, prefer using llvm-cov as the gcov wrapper
    if(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
      find_program(LLVM_COV_EXE NAMES llvm-cov)
      if(LLVM_COV_EXE)
        set(GCOVR_GCOV_OPTION --gcov-executable "${LLVM_COV_EXE} gcov")
      else()
        message(WARNING "llvm-cov not found! Coverage report will not be generated for Clang.")
        set(SKIP_COVERAGE TRUE)
      endif()
    endif()

    if(NOT SKIP_COVERAGE)
      add_custom_target(
        coverage-html
        COMMAND ${GCOVR_EXE} -r ${CMAKE_SOURCE_DIR} ${GCOVR_GCOV_OPTION} ${GCOVR_FILTER_ARGS} --html --html-details -o coverage.html
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
        COMMENT "Generating code coverage HTML report with gcovr for include folder only"
      )
      add_custom_target(
        coverage-xml
        COMMAND ${GCOVR_EXE} -r ${CMAKE_SOURCE_DIR} ${GCOVR_GCOV_OPTION} ${GCOVR_FILTER_ARGS} --xml-pretty -o coverage.xml
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
        COMMENT "Generating code coverage XML report with gcovr for include folder only"
      )
      add_custom_target(
        coverage
        DEPENDS coverage-html coverage-xml
        COMMENT "Aggregate target to generate all coverage reports"
      )
    endif()
  endif()
endif()
