cmake_minimum_required(VERSION 3.17)
project(CppSource)

# set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20")

include_directories(.)

add_executable(CppSource
        all.h
        main.cpp)
