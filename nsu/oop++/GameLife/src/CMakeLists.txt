cmake_minimum_required(VERSION 3.29)
project(src_project)

set(CMAKE_CXX_STANDARD 14)

add_library(src_lib
        GameRules.h
        GameRules.cpp
        Game.h
        Game.cpp
        GameField.h
        GameField.cpp
        GameUniverse.h
        GameUniverse.cpp
        FileReader.h
        FileReader.cpp
        UniReader.h
        UniReader.cpp
        UniWriter.h
        UniWriter.cpp
        CommandController.h
        OutputHandler.h
        OutputHandler.cpp
        CommandHandler.h
        CommandController.cpp
        CommandHandler.cpp)

target_include_directories(src_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
