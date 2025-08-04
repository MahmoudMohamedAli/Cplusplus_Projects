cmake_minimum_required(VERSION 3.22)

project(logger_project)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS " -g")

set(SOURCE_FILES
    test.cpp
)

# Create executable
add_executable(logger ${SOURCE_FILES})

# Add include directories to the target
target_include_directories(logger PRIVATE ${CMAKE_SOURCE_DIR}/include/)