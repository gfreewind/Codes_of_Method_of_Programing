
# CMake version
cmake_minimum_required (VERSION 2.8)

set(CMAKE_C_FLAGS "-g")

# Target name
project(rotate_string)

add_executable(rotate_string test_cases.cpp rotate_string.cpp)

TARGET_LINK_LIBRARIES(rotate_string gtest gtest_main pthread)


