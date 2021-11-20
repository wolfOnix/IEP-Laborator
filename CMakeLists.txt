# CMake version
cmake_minimum_required(VERSION 3.0)

# Set the name of the project
set(PROJECT_NAME devices)
project(${PROJECT_NAME})  

# Executable defining
add_executable(${PROJECT_NAME}
    src/main.cpp
    src/smartdevice.cpp
    src/device.cpp)
