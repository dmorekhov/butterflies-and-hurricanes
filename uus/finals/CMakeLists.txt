cmake_minimum_required(VERSION 3.29)
project(lab5)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(src)

add_executable(lab5
        main.cpp
)

target_link_libraries(lab5 src_lib)