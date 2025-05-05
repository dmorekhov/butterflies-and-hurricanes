cmake_minimum_required(VERSION 3.29)
project(task_2)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(src)

add_executable(task_2
        main.cpp
        )

target_link_libraries(task_2 src_lib)