cmake_minimum_required(VERSION 3.9)
project(cpp_indie_studio)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -W -Wall -Wextra")
set(CMAKE_AUTOMOC ON)


set(SRC_EXCEPTION
        src/Exception/Exception.cpp
        src/Exception/Exception.hpp)

set(SRC_INTERFACE
        src/Interface/ISerializable.hpp
        src/Interface/IRenderable.hpp
        src/Interface/ITransformable.hpp
        src/Interface/IAssetLoader.hpp
        src/Interface/IRenderWindow.hpp
        src/Interface/IGameScene.hpp
        src/Interface/IEventScene.hpp)

set(SRC_SCENE_GAME
        src/Scenes/SceneGame/SceneGame.hpp
        src/Scenes/SceneGame/SceneGame.cpp
        src/Scenes/SceneGame/Bomb.cpp
        src/Scenes/SceneGame/Bomb.hpp
        src/Scenes/General/GameInfo.hpp src/Scenes/General/PlayerInfo.cpp src/Scenes/General/PlayerInfo.hpp src/Scenes/General/GameInfo.cpp)


set(SRC_SCENE
        src/Scenes/SceneLauncher.cpp
        src/Scenes/SceneLauncher.hpp
        src/Scenes/General/Clock.cpp
        src/Scenes/General/Clock.hpp
        src/Scenes/General/AActivator.cpp
        src/Scenes/General/AActivator.hpp)

set(SRC_MAP
        src/Map/Map.cpp
        src/Map/Map.hpp
        src/Map/MapGenerator.cpp
        src/Map/MapGenerator.hpp
        src/Map/MapWall.cpp
        src/Map/MapWall.hpp
        src/Map/MapConstructor.cpp
        src/Map/MapConstructor.hpp)

set(SRC_MENU
        src/Menu/GraphicButton.cpp
        src/Menu/GraphicButton.hpp
        src/Menu/GraphicElement.cpp
        src/Menu/GraphicElement.hpp
        src/Menu/GraphicText.cpp
        src/Menu/GraphicText.hpp
        src/Menu/Menu.cpp
        src/Menu/Menu.hpp
        src/AObject.cpp
        src/AObject.hpp
        )

set(SRC_FILES
        src/Interface/IObject.hpp
        src/Map/MapWall.cpp
        src/Map/MapWall.hpp
        src/Render/GameEngine.cpp
        src/Render/GameEngine.hpp
        src/AnimatedObject.cpp
        src/AnimatedObject.hpp
        src/StaticObject.cpp
        src/StaticObject.hpp
        src/Render/EventHandler.cpp
        src/Render/EventHandler.hpp src/AObject.cpp src/AObject.hpp)

add_executable(
        bomberman
        ${SRC_INTERFACE}
        ${SRC_SCENE}
        ${SRC_SCENE_GAME}
        ${SRC_FILES}
        ${SRC_MAP}
        ${SRC_EXCEPTION}
        ${SRC_MENU}
        src/Bomberman.cpp)

add_executable(tests_map_gen
        ${SRC_MAP}
        ${SRC_EXCEPTION}
        ${SRC_FILES}
        tests/MapGen.cpp)
target_link_libraries(tests_map_gen Irrlicht)

target_link_libraries(bomberman Irrlicht)