cmake_minimum_required(VERSION 3.17)
project(list)

set(CMAKE_CXX_STANDARD 20)

add_executable(list main.cpp element.cpp element.h datatype.h list.cpp list.h queue.cpp queue.h iterator.cpp iterator.h array.h array.cpp)