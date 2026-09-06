# CMake configuration for dummy-cpp-project

cmake_minimum_required(VERSION 3.30)

project(DummyProject VERSION 1.2.3 LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

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
enable_testing()

add_executable(tests source/dummy.cpp test/test.cpp)
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)
add_test(NAME DummyTests COMMAND tests)
