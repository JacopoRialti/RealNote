cmake_minimum_required(VERSION 3.5)
project(RealNote)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(lib/googletest-main)

add_subdirectory(src)
add_subdirectory(tests)

