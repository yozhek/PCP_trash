cmake_minimum_required(VERSION 3.26)
project(trash)

set(CMAKE_CXX_STANDARD 17)

add_executable(trash trash/main.cpp)

add_executable(pisemka pisemka/main.cpp
        pisemka/Game.cpp)
