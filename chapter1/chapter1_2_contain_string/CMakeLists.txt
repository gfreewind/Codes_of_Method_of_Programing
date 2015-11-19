
# CMake version
cmake_minimum_required (VERSION 2.8)


set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -Werror")
set(CMAKE_CXX_FLAGS "-g -Wall -Werror")

set(CMAKE_VERBOSE_MAKEFILE ON)

# Target name
project(contain_chars)

add_executable(contain_chars test_cases.cpp contain_chars.cpp)

TARGET_LINK_LIBRARIES(contain_chars gtest gtest_main pthread)


