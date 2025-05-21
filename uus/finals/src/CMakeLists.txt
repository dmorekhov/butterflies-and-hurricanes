cmake_minimum_required(VERSION 3.29)
project(src_project)

set(CMAKE_CXX_STANDARD 14)

add_library(src_lib
        FlightsInfo.cpp
        FlightsInfo.h
        FlightsManager.h
        FlightsManager.cpp
        FlightsSearcher.cpp
        FlightsSearcher.h
        FlightsStats.cpp
        FlightsStats.h
        FlightStruct.cpp
        FlightStruct.h
)

target_include_directories(src_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})