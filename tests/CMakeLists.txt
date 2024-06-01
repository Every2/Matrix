cmake_minimum_required(VERSION 3.28)
project(tests)

set(CMAKE_CXX_STANDARD 20)

find_package(GTest)

add_executable(tests
        tests.cpp
)

target_link_libraries(tests gtest::gtest)

