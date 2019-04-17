cmake_minimum_required(VERSION 3.13)
project(test)

set(CMAKE_C_STANDARD 99)


add_executable(test main.c include/tasks.h src/task1.c src/task2.c)

target_link_libraries(test m)
