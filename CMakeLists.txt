cmake_minimum_required(VERSION 3.28)
project(matrix)

set(CMAKE_CXX_STANDARD 20)

add_executable(matrix
        include/matrix.hpp
        src/matrix.cpp)
