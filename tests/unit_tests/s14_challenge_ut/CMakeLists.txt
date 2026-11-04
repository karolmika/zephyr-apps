cmake_minimum_required(VERSION 3.20.0)

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})

project(s14_challenge_ut)

target_sources(app PRIVATE
    src/main.cpp
    ../../../applications/s14_challenge/src/MyStrings.cpp
     )

target_include_directories(app PRIVATE
    ../../../applications/s14_challenge/inc
)