
# CMake version
cmake_minimum_required (VERSION 2.8)


set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -Werror")
set(CMAKE_CXX_FLAGS "-g -Wall -Werror -std=c++11")

set(CMAKE_VERBOSE_MAKEFILE ON)

# Target name
project(echo_string)

add_executable(echo_string test_cases.cpp echo_string.cpp)

TARGET_LINK_LIBRARIES(echo_string gtest gtest_main pthread)


