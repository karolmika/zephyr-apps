 cmake_minimum_required(VERSION 3.20.0)

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})

project(s13_challenge_test)

target_sources(app PRIVATE
    src/main.cpp
    ../../../applications/s13_challenge/src/movie.cpp
    ../../../applications/s13_challenge/src/movies.cpp
     )

target_include_directories(app PRIVATE
    ../../../applications/s13_challenge/inc
)