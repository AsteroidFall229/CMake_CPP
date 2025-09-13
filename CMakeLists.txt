cmake_minimum_required(VERSION 3.31)
project(Knucklebones_SRII)

set(CMAKE_CXX_STANDARD 26)

add_executable(Knucklebones_SRII
        main.cpp
        box.h
        box.cpp
        tools_put.cpp
        Game_switch_process.cpp
)
