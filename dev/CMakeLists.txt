cmake_minimum_required(VERSION 4.0)

# On my windows pc use "cmake .. -G "MinGW Makefiles"

project(app)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED YES)

add_executable(exe
    src/main.cpp
    src/convert.cpp
    src/header.h)