cmake_minimum_required(VERSION 3.22)
project(unique_ptr_Impl)

set(CMAKE_CXX_FLAGS "-g")
set(CMAKE_CXX_STANDARD 20)
find_package(GTest REQUIRED) 
if(NOT GTest_FOUND)
    message(FATAL_ERROR "GTest not found"   )
endif()


add_executable(unique_ptr_Impl  gTest/unique_ptr_Test.cpp) #main.cpp)
target_include_directories(unique_ptr_Impl PRIVATE include)

## less /usr/share/cmake-3.22/Modules/FindGTest.cmake
target_link_libraries(
    ${PROJECT_NAME}
    GTest::gtest
    GTest::gmock_main
)

#gtest_discover_tests to let ctest know which test executables in its database

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME})