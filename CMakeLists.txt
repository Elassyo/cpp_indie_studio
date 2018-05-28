cmake_minimum_required(VERSION 3.10)
project(cpp_indie_studio)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -W -Wall -Wextra -std=c++17")
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

set(SRC_INTERFACE
        src/interface/ISerializable.hpp
        src/interface/IRenderable.hpp
        src/interface/ITransformable.hpp
        )

set(SRC_FILES
        src/AObject.cpp
        src/AObject.hpp
        src/ATransformableObject.cpp
        src/ATransformableObject.hpp
        )

add_executable(
        bomberman
        ${SRC_INTERFACE}
        ${SRC_FILES}
        src/main.cpp
)
target_link_libraries(bomberman Irrlicht)