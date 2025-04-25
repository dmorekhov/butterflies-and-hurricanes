cmake_minimum_required(VERSION 3.29)
project(laboneflight)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(laboneflight
    FlightsInfo.cpp
    FlightsInfo.h
    main.cpp)
