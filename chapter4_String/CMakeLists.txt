cmake_minimum_required(VERSION 3.25)
project(chapter4_String)

set(CMAKE_CXX_STANDARD 14)

add_executable(chapter4_String
        StaticString.h)

add_executable(kmp kmp.cpp)