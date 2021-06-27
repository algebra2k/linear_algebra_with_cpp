cmake_minimum_required (VERSION 3.8)

project ("linear_algebra")

set (CMAKE_CXX_STANDARD 11)

add_executable(test test.cc vector.h)