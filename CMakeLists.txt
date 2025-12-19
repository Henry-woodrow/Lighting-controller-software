cmake_minimum_required(VERSION 3.20)
project(lighting_desk LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(lighting_desk
    src/main.cpp
    src/engine.cpp
    src/dmx.cpp
)
