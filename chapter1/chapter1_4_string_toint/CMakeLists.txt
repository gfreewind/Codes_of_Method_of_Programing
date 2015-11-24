
# CMake version
cmake_minimum_required (VERSION 2.8)


set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -Werror")
set(CMAKE_CXX_FLAGS "-g -Wall -Werror -std=c++11")

set(CMAKE_VERBOSE_MAKEFILE ON)

# Target name
project(string_toint)

add_executable(string_toint test_cases.cpp string_toint.cpp)

TARGET_LINK_LIBRARIES(string_toint gtest gtest_main pthread)


