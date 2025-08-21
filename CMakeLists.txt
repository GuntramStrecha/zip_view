cmake_minimum_required(VERSION 3.17)

project(ZipViews LANGUAGES CXX VERSION 0.0.1)

enable_testing()

include(FetchContent)
include(CTest)

# Fetch Catch2
FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG v3.8.0
)
FetchContent_MakeAvailable(Catch2)

# Find clang-tidy and clang-format
find_program(CLANG_TIDY_EXE NAMES clang-tidy)
find_program(CLANG_FORMAT_EXE NAMES clang-format)

# Set variables
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_VERBOSE_MAKEFILE ON)

if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
	add_compile_options(-pedantic -Werror -Wall -Wextra -Wconversion -Wshadow -Wunused -Woverloaded-virtual -Wnon-virtual-dtor -Wold-style-cast -Wduplicated-cond -Wduplicated-branches -Wlogical-op -Wnull-dereference -Wuseless-cast -Wdouble-promotion -Wnrvo)
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
  add_compile_options(-Werror -Weverything -Wno-c++98-compat -Wno-c++98-compat-pedantic -Wno-c++-compat -Wno-padded)
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
  add_compile_options(/W4 /WX)
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

# Add gcovr target
if(CODE_COVERAGE)
  find_program(GCOVR_EXE NAMES gcovr)
  if(GCOVR_EXE)
    add_custom_target(
      coverage
      COMMAND ${GCOVR_EXE} -r ${CMAKE_SOURCE_DIR} --html --html-details -o coverage.html
      WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
      COMMENT "Generating code coverage report with gcovr"
    )
  else()
    message(WARNING "gcovr not found! Coverage report will not be generated.")
  endif()
endif()
