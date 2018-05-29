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

set(SRC_MAP
        src/map/Map.cpp
        src/map/Map.hpp
        src/map/MapGenerator.cpp
        src/map/MapGenerator.hpp
        )

set(SRC_MENU
        src/Menu/GraphicButton.cpp
        src/Menu/Include/GraphicButton.hpp
        src/Menu/Menu.cpp
        src/Menu/Include/Menu.hpp
        )

set(SRC_FILES
        src/AObject.cpp
        src/AObject.hpp
        src/ATransformableObject.cpp
        src/ATransformableObject.hpp
        src/map/MapWall.cpp
        src/map/MapWall.hpp
        )

add_executable(
        bomberman
        ${SRC_INTERFACE}
        ${SRC_FILES}
        ${SRC_MAP}
        ${SRC_MENU}
        src/main.cpp
)
target_link_libraries(bomberman Irrlicht)