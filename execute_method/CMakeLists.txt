cmake_minimum_required(VERSION 3.10)

# Project name
project(SocketApp LANGUAGES CXX)

# Use C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Sources (only .cpp files)
set(SOURCES
    src/Application.cpp
    src/main.cpp
)

# Executable target
add_executable(socket_app ${SOURCES})

# Tell compiler where to find headers in "inc"
target_include_directories(socket_app PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/inc)
