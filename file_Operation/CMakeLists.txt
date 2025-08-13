cmake_minimum_required(VERSION 3.5)

project(file_processing)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_COMPILER_FLAGS "-g"  )

add_executable(Read_write_normal Read_write_file.cpp)    
add_executable(Read_write_binary Read_write_binary_file.cpp)
add_executable(mergefiles mergefiles.cpp)