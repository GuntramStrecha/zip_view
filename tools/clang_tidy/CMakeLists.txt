cmake_minimum_required(VERSION 3.17)
project(zip_view_tidy)

option(BUILD_CLANG_TIDY_CHECKS "Build custom clang-tidy checks for zip_view" OFF)
if(NOT BUILD_CLANG_TIDY_CHECKS)
  message(STATUS "zip_view clang-tidy checks disabled (BUILD_CLANG_TIDY_CHECKS=OFF)")
  return()
endif()

# Find LLVM/Clang
find_package(LLVM REQUIRED CONFIG)
find_package(Clang REQUIRED CONFIG)

# Ensure clang-tidy specific headers (ClangTidy.h) are available.
# Look for the 'clang-tidy' include directory (prefer configured include dirs).
find_path(CLANG_TIDY_INCLUDE_DIR ClangTidy.h
          PATH_SUFFIXES clang-tidy
          HINTS ${Clang_INCLUDE_DIRS} ${LLVM_INCLUDE_DIRS})
if (NOT CLANG_TIDY_INCLUDE_DIR)
  message(FATAL_ERROR "clang-tidy headers not found. Install the clang-tidy development package (e.g. libclang-tidy-dev / clang-tools).")
endif()

# Include directories and compile definitions will be applied to the plugin target
# using modern CMake target_* commands (see below).

set(SOURCES
  NoVirtualCheck.cpp
  RttiCheck.cpp
  SmartPtrCheck.cpp
  NoexceptThrowCheck.cpp
  RegisterZipViewChecks.cpp
)

add_library(zipview_tidy MODULE ${SOURCES})
# Name plugin so extension is .so on Unix etc.
set_target_properties(zipview_tidy PROPERTIES PREFIX "" OUTPUT_NAME "zipview_tidy")

# Link with clang tidy components
target_link_libraries(zipview_tidy PRIVATE
  clangAST
  clangASTMatchers
  clangBasic
  clangFrontend
  clangTidy
  clangTidyUtils
  clangTooling
)

# Configure target include directories and compile definitions using modern CMake
target_include_directories(zipview_tidy PRIVATE ${LLVM_INCLUDE_DIRS} ${Clang_INCLUDE_DIRS} ${CLANG_TIDY_INCLUDE_DIR})
if (LLVM_DEFINITIONS)
  target_compile_definitions(zipview_tidy PRIVATE ${LLVM_DEFINITIONS})
endif()

# Install plugin into build directory for easy loading
set_target_properties(zipview_tidy PROPERTIES LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/clang_tidy_plugins")
message(STATUS "zip_view clang-tidy checks will be built and output to ${CMAKE_BINARY_DIR}/clang_tidy_plugins")
