cmake_minimum_required(VERSION 3.28)

set(project lab07)

project(${project})

set(CMAKE_CXX_STANDARD 20)

set(${project}_SOURCES main.cpp)

add_subdirectory(MyLib)


set(${project}_SOURCE_LIST ${${project}_SOURCES})

add_executable(${project} ${${project}_SOURCE_LIST}) 

target_link_libraries(${project} MyLib)


