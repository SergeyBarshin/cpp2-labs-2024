cmake_minimum_required(VERSION 3.27)

set(project "mymath")
project(${project})

set(CMAKE_CXX_STANDARD 20)

set(${project}_SOURCES mymath.cpp)

set(${project}_HEADERS mymath.h)

set(${project}_SOURCE_LIST
        ${${project}_SOURCES}
        ${${project}_HEADERS})

add_library(${project}
        STATIC
        ${${project}_SOURCE_LIST})