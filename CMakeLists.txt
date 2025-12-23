cmake_minimum_required(VERSION 3.20)
project(lighting_desk LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Engine library (compile once)
add_library(light_engine_lib
    src/light_engine.cpp
    src/dmx.cpp
)

target_include_directories(light_engine_lib
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

# App executable (link against the library)
add_executable(lighting_desk
    src/main.cpp
    src/dmx.cpp
)

target_link_libraries(lighting_desk
    PRIVATE
    light_engine_lib
)

# Tests (optional folder)
enable_testing()
add_subdirectory(tests)
