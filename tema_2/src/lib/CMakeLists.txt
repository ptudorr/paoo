cmake_minimum_required(VERSION 3.10)

add_library(aparateZbor_lib STATIC Avion.cpp AvionCargo.cpp AvionComercial.cpp Elicopter.cpp)
target_include_directories(aparateZbor_lib PUBLIC "${CMAKE_SOURCE_DIR}/include")

