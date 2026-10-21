cmake_minimum_required(VERSION 3.20.0)

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(s13_challenge)

target_sources(app PRIVATE 
    src/main.cpp
    src/movie.cpp
    src/movies.cpp
)
target_include_directories(app PRIVATE inc)