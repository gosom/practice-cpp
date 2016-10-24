cmake_minimum_required(VERSION 3.5)
project(arrays_proj)

add_definitions(-std=c++11)
add_definitions(-Werror)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -D_GLIBCXX_DEBUG")

set(SOURCE_FILES main.cpp)

include_directories(../catch)
add_executable(arrays ${SOURCE_FILES})
