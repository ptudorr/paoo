cmake_minimum_required(VERSION 3.10)

add_library(avion_lib STATIC avion.cpp)

target_include_directories(avion_lib PUBLIC "${CMAKE_SOURCE_DIR}/include")

