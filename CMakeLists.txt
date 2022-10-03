cmake_minimum_required(VERSION 3.22)
project(matrix)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -Wextra")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include_directories(include)

add_executable(ex00 srcs/ex00.cpp)
add_executable(ex01 srcs/ex01.cpp)
add_executable(ex02 srcs/ex02.cpp)
add_executable(ex03 srcs/ex03.cpp)
add_executable(ex04 srcs/ex04.cpp)
add_executable(ex05 srcs/ex05.cpp)
