cmake_minimum_required(VERSION 3.26)
project(trash)

set(CMAKE_CXX_STANDARD 17)

add_executable(trash trash/main.cpp)

add_executable(Hangman Hangman/main.cpp
        Hangman/Game.cpp)

add_executable(Tesla Tesla/main.cpp
        Tesla/Tesla.cpp
        Tesla/Game.cpp
        Tesla/Map.cpp
        Tesla/Supercharger.cpp
        Tesla/Position.cpp)