cmake_minimum_required(VERSION 3.12)

project(Advent_of_Code_2023 CXX)

add_library(helpers STATIC
        helpers/helpers.cpp
        helpers/helpers.h
        helpers/helpers.cpp)

add_executable(day_01 day_01/day_01.cpp
        helpers/helpers.cpp)

target_link_libraries(day_01 helpers)