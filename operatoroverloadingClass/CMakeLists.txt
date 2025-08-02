
cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_COMPILER g++)

project(operatoroverloadingClass
        VERSION 1.0
        DESCRIPTION "Operator Overloading Class Example"
        LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(cmake_compiler_flags "-g")

add_executable(operatoroverloadingClass
        main.cpp
        src/Complex.cpp)

include_directories(CustomString "./include")

add_library(ComplexLib STATIC
        src/Complex.cpp)        