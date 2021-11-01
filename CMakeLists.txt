# CMake version
cmake_minimum_required(VERSION 3.0)

# The name of the project
project(devices)

# Header files directory
include_directories(inc)

# C++ standards
if(CMAKE_VERSION GREATER "3.1.2") 
    set(CMAKE_CXX_STANDARD 14)
    set(CMAKE_CXX_STANDARD_REQUIRED ON)
    set(CMAKE_CXX_EXTENSIONS OFF)
else()
    if(CMAKE_COMPILER_IS_GNUCXX)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
    endif()    
endif()    

# Executable defining
add_executable(${PROJECT_NAME}
    inc/device.hpp
    src/main.cpp
    src/device.cpp)

