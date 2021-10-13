cmake_minimum_required(VERSION 3.16.3)
project(test)

SET(CMAKE_CXX_FLAGS "-g -O0 -Wall -fprofile-arcs -ftest-coverage -pthread")
SET(CMAKE_C_FLAGS "-g -O0 -Wall -W -D_DEBUG -fprofile-arcs -ftest-coverage")
SET(CMAKE_EXE_LINKER_FLAGS "-fprofile-arcs -ftest-coverage")

add_library(mylib STATIC mylib.c mylib.h)

add_executable(main main.c)
target_link_libraries(main mylib)

find_package(GTest REQUIRED)

include_directories(${GTEST_INCLUDE_DIRS})
add_executable(mylib_tests mylib_tests.cpp)
target_link_libraries(mylib_tests ${GTEST_LIBRARIES} mylib)