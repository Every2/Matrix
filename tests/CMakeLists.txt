cmake_minimum_required(VERSION 3.28)
project(tests)

set(CMAKE_CXX_STANDARD 20)

find_package(GTest)
find_package(Boost)

add_executable(tests
        tests.cpp
        ../include/specialized_functions.h
)

target_link_libraries(tests gtest::gtest)
target_link_libraries(tests boost::boost)
