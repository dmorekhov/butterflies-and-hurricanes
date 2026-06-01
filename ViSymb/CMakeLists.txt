cmake_minimum_required(VERSION 3.29)
project(ViSymb)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")
set(CMAKE_PREFIX_PATH "C:\\Qt\\6.4.2\\mingw_64")

find_package(Qt6 REQUIRED COMPONENTS Core)

include_directories(.
src/
src/core
src/ui)

add_executable(ViSymb
        src/main.cpp
        src/core/SymbolManager.cpp
        src/core/SymbolManager.h
        src/core/JsonReader.h
        src/core/JsonReader.cpp
)

target_link_libraries(ViSymb PRIVATE Qt6::Core)