cmake_minimum_required(VERSION 2.8)
project(paro_stl)

set(CMAKE_CXX_FLAGS "-std=c++11 -Wall -Wfatal-errors")

add_subdirectory(gmock-1.7.0)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
set(LIBS gtest gtest_main)

add_executable(dup dup.cpp)
target_link_libraries(dup ${LIBS})

add_executable(cheap cheap.cpp)
target_link_libraries(cheap ${LIBS})

add_executable(pow2 pow2.cpp)
target_link_libraries(pow2 ${LIBS})
