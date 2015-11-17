
# CMake version
cmake_minimum_required (VERSION 2.8)


set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -Werror")
set(CMAKE_CXX_FLAGS "-g -Wall -Werror")

set(CMAKE_VERBOSE_MAKEFILE ON)

# Target name
project(rotate_string)

add_executable(rotate_string test_cases.cpp rotate_string.cpp)

TARGET_LINK_LIBRARIES(rotate_string gtest gtest_main pthread)


