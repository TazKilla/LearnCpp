cmake_minimum_required(VERSION 3.5.0)
project(learncpp VERSION 0.1.0 LANGUAGES C CXX)

include(FindPkgConfig)
#pkg_search_module(SDL2 REQUIRED sdl2)
#pkg_search_module(SDL2_IMAGE REQUIRED sdl2_image)

add_compile_options(-Warray-bounds -g)

INCLUDE_DIRECTORIES(
    #${SDL2_INCLUDE_DIRS}
    #${sdl2_image}
)

SET (CMAKE_RUNTIME_OUTPUT_DIRECTORY learncpp)

add_executable(learncpp src/main.cpp)
set_property(TARGET learncpp PROPERTY CXX_STANDARD 20)

Target_Link_Libraries (
    learncpp
    #${SDL2_LIBRARIES}
    #${SDL2_IMAGE}
    m
)
