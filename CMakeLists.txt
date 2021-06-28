cmake_minimum_required (VERSION 3.8)

project ("linear_algebra")

set (CMAKE_CXX_STANDARD 11)

set (SRCS src/vector.cpp src/vector.hpp)

add_library(linearalgebra ${SRCS})


include_directories(src)

add_executable(test test.cc)

target_link_libraries(test linearalgebra)

