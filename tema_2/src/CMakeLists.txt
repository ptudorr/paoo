cmake_minimum_required(VERSION 3.10)

project(tema_2)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(lib)

add_executable(tema_2 main.cpp)

target_link_libraries(tema_2 PUBLIC aparateZbor_lib)

target_include_directories(tema_2 PUBLIC "${CMAKE_SOURCE_DIR}/include")