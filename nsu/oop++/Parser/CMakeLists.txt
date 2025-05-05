cmake_minimum_required(VERSION 3.26)
project(23202_orekhov_oop_cpp)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(GoogleTest)

add_executable(23202_orekhov_oop_cpp task-0.cpp
        FileReader.h
        FileReader.cpp
        Parser.h
        Parser.cpp
        Statistic.h
        Statistic.cpp
        FileWriter.h
        FileWriter.cpp
)
