cmake_minimum_required(VERSION 3.16)
project(matrix)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -Wextra")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include_directories(include)

add_executable(ex00 srcs/ex00.cpp srcs/float_utils.cpp)
add_executable(ex01 srcs/ex01.cpp srcs/float_utils.cpp)
add_executable(ex02 srcs/ex02.cpp srcs/float_utils.cpp)
add_executable(ex03 srcs/ex03.cpp srcs/float_utils.cpp)
add_executable(ex04 srcs/ex04.cpp srcs/float_utils.cpp)
add_executable(ex05 srcs/ex05.cpp srcs/float_utils.cpp)
add_executable(ex06 srcs/ex06.cpp srcs/float_utils.cpp)
add_executable(ex07 srcs/ex07.cpp srcs/float_utils.cpp)
add_executable(ex08 srcs/ex08.cpp srcs/float_utils.cpp)
add_executable(ex09 srcs/ex09.cpp srcs/float_utils.cpp)
add_executable(ex10 srcs/ex10.cpp srcs/float_utils.cpp)
add_executable(ex11 srcs/ex11.cpp srcs/float_utils.cpp)
add_executable(ex12 srcs/ex12.cpp srcs/float_utils.cpp)
add_executable(ex13 srcs/ex13.cpp srcs/float_utils.cpp)

# Bonus
add_executable(ex14 srcs/ex14.cpp srcs/float_utils.cpp)

# Bonus 15
add_executable(ex15 srcs/ex15/main.cpp
                    srcs/ex15/ex00.cpp
                    srcs/ex15/ex01.cpp
                    srcs/ex15/ex02.cpp
                    srcs/ex15/ex03.cpp
                    srcs/ex15/ex04.cpp
                    srcs/ex15/ex05.cpp
                    srcs/ex15/ex06.cpp
                    srcs/ex15/ex07.cpp
                    srcs/ex15/ex08.cpp
                    srcs/ex15/ex09.cpp
                    srcs/ex15/ex10.cpp
                    srcs/ex15/ex11.cpp
                    srcs/ex15/ex12.cpp
                    srcs/ex15/ex13.cpp
        srcs/float_utils.cpp)
