cmake_minimum_required(VERSION 3.20)

project(Solar_system_simulator)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(header)

find_package(SFML 3 REQUIRED COMPONENTS Graphics Window System)

add_executable(Solar_system_simulator
        src/main.cpp
        src/planet.cpp
)

target_link_libraries(Solar_system_simulator
        SFML::Graphics
        SFML::Window
        SFML::System
)
