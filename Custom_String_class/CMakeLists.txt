cmake_minimum_required(VERSION 3.15)

set(CMAKE_CXX_COMPILER g++)
set(CMAKE_C_COMPILER gcc)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g ")

project(CustomString)

add_executable(CustomString
    main.cpp
    src/StringCustom.cpp
)

include_directories(CustomString "./include")

add_library(custom_lib_string STATIC
    src/StringCustom.cpp
)
