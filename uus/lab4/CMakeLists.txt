cmake_minimum_required(VERSION 3.29)
project(lab4)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(lab4
        FlightsInfo.cpp
        FlightsInfo.h
        main.cpp
        FlightsStats.cpp
        FlightsStats.h
        FlightStruct.h)
