cmake_minimum_required(VERSION 3.10)
project(cpp_indie_studio)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -W -Wall -Wextra -std=c++17")
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

set(SRC_FILES
        )

add_executable(
        bomberman
        src/main.cpp)
target_link_libraries(bomberman Irrlicht)