cmake_minimum_required(VERSION 3.5)
project(Impl_Shared_pointer)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -g")

find_package(GTest REQUIRED)
if(NOT GTEST_FOUND)
    message(FATAL_ERROR "GTest not found"   )
endif()
set(src_files gTest/shr_ptr_test.cpp)

add_executable(Impl_Shared_pointer ${src_files}) 

target_include_directories(Impl_Shared_pointer PUBLIC include)

# less /usr/share/cmake-3.22/Modules/FindGTest.cmake
target_link_libraries(
    ${PROJECT_NAME}
    GTest::gtest
    GTest::gmock_main
)

#gtest_discover_tests to let ctest know which test executables in its database

include(GoogleTest)
