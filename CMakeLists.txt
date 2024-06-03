cmake_minimum_required(VERSION 3.28)
project(matrix)

set(CMAKE_CXX_STANDARD 20)

find_package(Boost)

add_executable(matrix
        include/matrix.hpp
        include/specialized_functions.h
)

target_link_libraries(matrix boost::boost)
