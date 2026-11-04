cmake_minimum_required(VERSION 3.20.0)

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(s14_challenge)

target_sources(app PRIVATE main.cpp src/MyStrings.cpp)

target_include_directories(app PRIVATE inc)