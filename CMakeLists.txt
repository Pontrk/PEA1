cmake_minimum_required(VERSION 3.26)
project(pea1)

set(CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc")

add_executable(pea1 main.cpp
        adjacency_matrix.cpp
        adjacency_matrix.h
        brute_force.cpp
        brute_force.h
)
