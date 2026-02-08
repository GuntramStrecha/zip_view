# Fetch Catch2 if not already available
if(NOT TARGET Catch2::Catch2WithMain)
  FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG v3.8.0
  )
  FetchContent_MakeAvailable(Catch2)
endif()

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

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
if(CODE_COVERAGE AND CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
  target_compile_options(ZipViewTests PRIVATE --coverage -O0 -g)
  target_link_options(ZipViewTests PRIVATE --coverage)
endif()
