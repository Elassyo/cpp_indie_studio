cmake_minimum_required(VERSION 3.9)
project(cpp_indie_studio)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -W -Wall -Wextra")
set(CMAKE_AUTOMOC ON)


set(SRC_EXCEPTION
        src/Exception/Exception.cpp
        src/Exception/Exception.hpp
        )

set(SRC_INTERFACE
        src/Interface/ISerializable.hpp
        src/Interface/IRenderable.hpp
        src/Interface/ITransformable.hpp
        src/Interface/IAssetLoader.hpp
        src/Interface/IRenderWindow.hpp src/Interface/IGameScene.hpp)

set(SRC_SCENE
        src/Scene/SceneLauncher.cpp
        src/Scene/SceneLauncher.hpp
        src/Scene/SceneGame.hpp
        src/Scene/SceneGame.cpp)


set(SRC_MAP
        src/Map/Map.cpp
        src/Map/Map.hpp
        src/Map/MapGenerator.cpp
        src/Map/MapGenerator.hpp
        src/Map/MapWall.cpp
        src/Map/MapWall.hpp
        src/Map/MapConstructor.cpp
        src/Map/MapConstructor.hpp
        )

set(SRC_MENU
        src/Menu/GraphicButton.cpp
        src/Menu/GraphicButton.hpp
        src/Menu/GraphicElement.cpp
        src/Menu/GraphicElement.hpp
        src/Menu/GraphicText.cpp
        src/Menu/GraphicText.hpp
        src/Menu/Menu.cpp
        src/Menu/Menu.hpp
        )

set(SRC_FILES
        src/IObject.cpp
        src/IObject.hpp
        src/Map/MapWall.cpp
        src/Map/MapWall.hpp
        src/Render/GameEngine.cpp
        src/Render/GameEngine.hpp
        src/AnimatedObject.cpp
        src/AnimatedObject.hpp
        src/StaticObject.cpp
        src/StaticObject.hpp)

add_executable(
        bomberman
        ${SRC_INTERFACE}
        ${SRC_SCENE}
        ${SRC_FILES}
        ${SRC_MAP}
        ${SRC_EXCEPTION}
        ${SRC_MENU}
        src/Bomberman.cpp
)

add_executable(tests_map_gen
        ${SRC_MAP}
        ${SRC_EXCEPTION}
        ${SRC_FILES}
        tests/MapGen.cpp)
target_link_libraries(tests_map_gen Irrlicht)

target_link_libraries(bomberman Irrlicht)