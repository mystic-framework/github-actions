# CMake configuration for dummy-cpp-project

cmake_minimum_required(VERSION 3.30)

project(DummyProject VERSION 1.2.3 LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Coverage Option
option(MYSTIC_ENABLE_COVERAGE "Enable code coverage instrumentation" OFF)

if(MYSTIC_ENABLE_COVERAGE)
  if(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    add_compile_options(-fprofile-instr-generate -fcoverage-mapping)
    add_link_options(-fprofile-instr-generate -fcoverage-mapping)
  elseif(CMAKE_CXX_COMPILER_ID MATCHES "GNU")
    add_compile_options(--coverage)
    add_link_options(--coverage)
  endif()
endif()

# Include directories
include_directories("${CMAKE_SOURCE_DIR}/source")

# Executable target
add_executable(project source/dummy.cpp source/main.cpp)

# Tests
include(FetchContent)
FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.8.1
)

FetchContent_MakeAvailable(Catch2)
list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/extras)

enable_testing()
add_executable(tests source/dummy.cpp test/test.cpp)
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)

include(Catch)
catch_discover_tests(tests)
