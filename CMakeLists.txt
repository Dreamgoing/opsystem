cmake_minimum_required(VERSION 3.3)
project(opsystem)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES grep.cpp)
add_executable(grep ${SOURCE_FILES})