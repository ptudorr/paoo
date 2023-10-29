cmake_minimum_required(VERSION 3.0)

project(tema_1)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(lib)

add_executable(tema_1 main.cpp)

target_link_libraries(tema_1 PUBLIC avion_lib)

target_include_directories(avion_lib PUBLIC "${CMAKE_SOURCE_DIR}/include")