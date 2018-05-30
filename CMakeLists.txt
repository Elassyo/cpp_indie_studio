cmake_minimum_required(VERSION 3.10)
project(cpp_indie_studio)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -W -Wall -Wextra")
set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)


set(SRC_EXCEPTION
        src/Exception/Exception.cpp
        src/Exception/Exception.hpp
        )

set(SRC_INTERFACE
        src/Interface/ISerializable.hpp
        src/Interface/IRenderable.hpp
        src/Interface/ITransformable.hpp
        src/Interface/IAssetLoader.hpp
        )

set(SRC_MAP
        src/Map/Map.cpp
        src/Map/Map.hpp
        src/Map/MapGenerator.cpp
        src/Map/MapGenerator.hpp
        src/Map/MapWall.cpp
        src/Map/MapWall.hpp
        )

set(SRC_MENU
        src/Menu/GraphicButton.cpp
        src/Menu/GraphicButton.hpp
        src/Menu/Menu.cpp
        src/Menu/Menu.hpp
        )

set(SRC_FILES
        src/AObject.cpp
        src/AObject.hpp
        src/ATransformableObject.cpp
        src/ATransformableObject.hpp
        src/Map/MapWall.cpp
        src/Map/MapWall.hpp
        src/Render/GameWindow.cpp
        src/Render/GameWindow.hpp
        )

add_executable(
        bomberman
        ${SRC_INTERFACE}
        ${SRC_FILES}
        ${SRC_MAP}
        ${SRC_EXCEPTION}
        ${SRC_MENU}
        src/Bomberman.cpp
)

target_link_libraries(bomberman Irrlicht)
