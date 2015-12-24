
# CMake version
cmake_minimum_required (VERSION 2.8)


set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -Werror")
set(CMAKE_CXX_FLAGS "-g -Wall -Werror -std=c++11")

set(CMAKE_VERBOSE_MAKEFILE ON)

# Target name
project(jump_steps)

add_executable(jump_steps test_cases.cpp jump_steps.cpp)

TARGET_LINK_LIBRARIES(jump_steps gtest gtest_main pthread)


