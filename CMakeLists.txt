cmake_minimum_required(VERSION 3.16)

project(fraction)

set(PROJECT fraction)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_EXE main.cpp)

set(SOURCE_LIB fraction.cpp fraction.h)

add_library(fraction_lib STATIC ${SOURCE_LIB})

add_executable(${PROJECT} ${SOURCE_EXE})

target_link_libraries(${PROJECT} fraction_lib)