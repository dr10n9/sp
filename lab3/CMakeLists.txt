cmake_minimum_required(VERSION 3.13)
project(lab3 C)

set(CMAKE_C_STANDARD 99)

add_executable(lab3 main.c task2.c task2.h task1.h task1.c)

target_link_libraries(lab3 rt)