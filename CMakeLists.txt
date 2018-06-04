cmake_minimum_required(VERSION 3.9)
project(cpp_indie_studio)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -W -Wall -Wextra")
set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)


set(SRC_FILES
        src/Audio/AudioDevice.cpp
        src/Audio/AudioDevice.hpp
        src/Audio/AudioFile.cpp
        src/Audio/AudioFile.hpp

        src/Exception/Exception.cpp
        src/Exception/Exception.hpp

        src/Interface/IAssetLoader.hpp
        src/Interface/IEventScene.hpp
        src/Interface/IGameScene.hpp
        src/Interface/IObject.hpp
        src/Interface/IRenderable.hpp
        src/Interface/IRenderWindow.hpp
        src/Interface/ISerializable.hpp
        src/Interface/ITransformable.hpp

        src/Map/Map.cpp
        src/Map/Map.hpp
        src/Map/MapBlocks/AMapBlock.cpp
        src/Map/MapBlocks/AMapBlock.hpp
        src/Map/MapBlocks/MapBlockBreakable.cpp
        src/Map/MapBlocks/MapBlockBreakable.hpp
        src/Map/MapBlocks/MapBlockUnbreakable.cpp
        src/Map/MapBlocks/MapBlockUnbreakable.hpp
        src/Map/MapConstructor.cpp
        src/Map/MapConstructor.hpp
        src/Map/MapGenerator.cpp
        src/Map/MapGenerator.hpp

        src/Menu/GraphicButton.cpp
        src/Menu/GraphicButton.hpp
        src/Menu/GraphicElement.cpp
        src/Menu/GraphicElement.hpp
        src/Menu/GraphicText.cpp
        src/Menu/GraphicText.hpp
        src/Menu/Menu.cpp
        src/Menu/Menu.hpp

        src/Render/EventHandler.cpp
        src/Render/EventHandler.hpp
        src/Render/GameEngine.cpp
        src/Render/GameEngine.hpp

        src/Scenes/General/AActivator.cpp
        src/Scenes/General/AActivator.hpp
        src/Scenes/General/Clock.cpp
        src/Scenes/General/Clock.hpp
        src/Scenes/General/GameInfo.cpp
        src/Scenes/General/GameInfo.hpp
        src/Scenes/General/PlayerInfo.cpp
        src/Scenes/General/PlayerInfo.hpp
        src/Scenes/SceneGame/Bomb.cpp
        src/Scenes/SceneGame/Bomb.hpp
        src/Scenes/SceneGame/Powers/BombDown.cpp
        src/Scenes/SceneGame/Powers/BombDown.hpp
        src/Scenes/SceneGame/Powers/BombPass.cpp
        src/Scenes/SceneGame/Powers/BombPass.hpp
        src/Scenes/SceneGame/Powers/BombUp.cpp
        src/Scenes/SceneGame/Powers/BombUp.hpp
        src/Scenes/SceneGame/Powers/FireDown.cpp
        src/Scenes/SceneGame/Powers/FireDown.hpp
        src/Scenes/SceneGame/Powers/FireUp.cpp
        src/Scenes/SceneGame/Powers/FireUp.hpp
        src/Scenes/SceneGame/Powers/Power.cpp
        src/Scenes/SceneGame/Powers/Power.hpp
        src/Scenes/SceneGame/Powers/SpeedDown.cpp
        src/Scenes/SceneGame/Powers/SpeedDown.hpp
        src/Scenes/SceneGame/Powers/SpeedUp.cpp
        src/Scenes/SceneGame/Powers/SpeedUp.hpp
        src/Scenes/SceneGame/Powers/WallPass.cpp
        src/Scenes/SceneGame/Powers/WallPass.hpp
        src/Scenes/SceneGame/SceneGame.cpp
        src/Scenes/SceneGame/SceneGame.hpp
        src/Scenes/SceneHomeMenu/SceneHomeMenu.cpp
        src/Scenes/SceneHomeMenu/SceneHomeMenu.hpp
        src/Scenes/SceneLauncher.cpp
        src/Scenes/SceneLauncher.hpp

        src/AnimatedObject.cpp
        src/AnimatedObject.hpp
        src/AObject.cpp
        src/AObject.hpp
        src/StaticObject.cpp
        src/StaticObject.hpp)

add_executable(bomberman
        ${SRC_FILES}
        src/Bomberman.cpp)

add_executable(tests_map_gen
        ${SRC_FILES}
        tests/MapGen.cpp)

target_link_libraries(tests_map_gen Irrlicht openal vorbisfile)

target_link_libraries(bomberman Irrlicht openal vorbisfile)
