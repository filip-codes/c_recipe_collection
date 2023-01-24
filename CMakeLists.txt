cmake_minimum_required(VERSION 3.23)
project(Recipe_Collection C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_FLAGS "-lncurses")

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

add_executable(Recipe_Collection main.c)

target_link_libraries(Recipe_Collection ${CURSES_LIBRARIES})