cmake_minimum_required(VERSION 3.10)
project(CustomVector)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_COMPILER_IS_GNUCXX ON)
set(CMAKE_CXX_FLAGS "-g")

find_package(GTest REQUIRED) # /usr/share/cmake-3.16/Modules/ --->GTestConfig.cmake

if(NOT GTest_FOUND)
    message(FATAL_ERROR "GTest not found"   )
endif()

set(src_files gTest/vecTest.cpp)

add_executable(CustomVector 
               ${src_files}) 

target_include_directories(CustomVector PRIVATE Vector)

## less /usr/share/cmake-3.22/Modules/FindGTest.cmake
target_link_libraries(
    ${PROJECT_NAME}
    GTest::gtest
    GTest::gmock_main
)

#gtest_discover_tests to let ctest know which test executables in its database

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME})
