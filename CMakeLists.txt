cmake_minimum_required(VERSION 3.27)
project(sw_battle)

set(CMAKE_CXX_STANDARD 20)

file(GLOB_RECURSE SOURCES src/*.cpp src/*.hpp)
add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC src/)

option(WITH_TESTS "WITH_TESTS" OFF)

if(WITH_TESTS)
    add_subdirectory(tests)
endif()