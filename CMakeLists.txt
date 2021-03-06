cmake_minimum_required(VERSION 3.9)
project(cpp_indie_studio)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)

if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
    add_compile_options("-W" "-Wall" "-Wextra")
    add_compile_options("$<$<CONFIG:DEBUG>:-DBOMB_VERSION=LINUX_DEV>")
    add_compile_options("$<$<CONFIG:RELEASE>:-DBOMB_VERSION=LINUX_REL>")
    set(LIBOPENAL_NAME openal)
    set(LIBVORBISFILE_NAME vorbisfile)
elseif("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
    add_compile_options("/DBOMB_VERSION=WINDOWS")
    include_directories(
            "C:\\irrlicht-1.8.4\\include"
            "C:\\Program Files (x86)\\OpenAL 1.1 SDK\\include"
            "C:\\libogg-1.3.3\\include"
            "C:\\libvorbis-1.3.6\\include")
    link_directories(
            "C:\\irrlicht-1.8.4\\lib\\Win64-visualStudio"
            "C:\\Program Files (x86)\\OpenAL 1.1 SDK\\libs\\Win64"
            "C:\\libvorbis-1.3.6\\win32\\VS2010\\x64\\Release")
    set(LIBOPENAL_NAME OpenAL32)
    set(LIBVORBISFILE_NAME libvorbisfile)

    set(LIBEXTRA_NAME Shell32)

    set(SRC_RESOURCES
            win/bombermario.rc)
endif()

set(SRC_FILES
        src/Audio/AudioBuffer.cpp
        src/Audio/AudioBuffer.hpp
        src/Audio/AudioManager.cpp
        src/Audio/AudioManager.hpp

        src/Exception/Exception.cpp
        src/Exception/Exception.hpp

        src/Interface/IAssetManager.hpp
        src/Interface/IAssetLoader.hpp
        src/Interface/IEventScene.hpp
        src/Interface/IGameScene.hpp
        src/Interface/IObject.hpp
        src/Interface/IRenderable.hpp
        src/Interface/IRenderWindow.hpp
        src/Interface/ISerializable.hpp
        src/Interface/ITransformable.hpp
        src/Interface/IPlayerController.hpp
        src/Interface/IAudioPlayer.hpp
        src/Interface/IAudioListener.hpp

        src/Map/BomberMap.cpp
        src/Map/BomberMap.hpp
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
        src/Menu/GraphicImage.cpp
        src/Menu/GraphicImage.hpp
        src/Menu/Menu.cpp
        src/Menu/Menu.hpp

        src/Player/AIController.cpp
        src/Player/AIController.hpp
        src/Player/PlayerActionner.cpp
        src/Player/PlayerActionner.hpp

        src/Render/EventHandler.cpp
        src/Render/EventHandler.hpp
        src/Render/GameEngine.cpp
        src/Render/GameEngine.hpp

        src/Scenes/General/AActivator.cpp
        src/Scenes/General/AActivator.hpp
        src/Scenes/General/CharacterLoader.cpp
        src/Scenes/General/CharacterLoader.hpp
        src/Scenes/General/CharacterInfo.cpp
        src/Scenes/General/CharacterInfo.hpp
        src/Scenes/General/Clock.cpp
        src/Scenes/General/Clock.hpp
        src/Scenes/General/Game.cpp
        src/Scenes/General/Game.hpp
        src/Scenes/General/PersistentInfo.cpp
        src/Scenes/General/PersistentInfo.hpp
        src/Scenes/General/PlayerInfo.cpp
        src/Scenes/General/PlayerInfo.hpp
        src/Scenes/General/Player.cpp
        src/Scenes/General/Player.hpp
        src/Scenes/General/AScene.cpp
        src/Scenes/General/AScene.hpp

        src/Scenes/SceneGame/Bomb.cpp
        src/Scenes/SceneGame/Bomb.hpp
        src/Scenes/SceneGame/ExplosionBlast.cpp
        src/Scenes/SceneGame/ExplosionBlast.hpp
        src/Scenes/SceneGame/Powers/BombDown.cpp
        src/Scenes/SceneGame/Powers/BombDown.hpp
        src/Scenes/SceneGame/Powers/BombFull.cpp
        src/Scenes/SceneGame/Powers/BombFull.hpp
        src/Scenes/SceneGame/Powers/BombPass.cpp
        src/Scenes/SceneGame/Powers/BombPass.hpp
        src/Scenes/SceneGame/Powers/BombUp.cpp
        src/Scenes/SceneGame/Powers/BombUp.hpp
        src/Scenes/SceneGame/Powers/FireDown.cpp
        src/Scenes/SceneGame/Powers/FireDown.hpp
        src/Scenes/SceneGame/Powers/FireFull.cpp
        src/Scenes/SceneGame/Powers/FireFull.hpp
        src/Scenes/SceneGame/Powers/FireUp.cpp
        src/Scenes/SceneGame/Powers/FireUp.hpp
        src/Scenes/SceneGame/Powers/Power.cpp
        src/Scenes/SceneGame/Powers/Power.hpp
        src/Scenes/SceneGame/Powers/PowerFactory.cpp
        src/Scenes/SceneGame/Powers/PowerFactory.hpp
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
        src/Scenes/SceneOptionMenu/SceneOptionMenu.cpp
        src/Scenes/SceneOptionMenu/SceneOptionMenu.hpp
        src/Scenes/SceneKeyMenu/IrrKeyToStr.cpp
        src/Scenes/SceneKeyMenu/IrrKeyToStr.hpp
        src/Scenes/SceneKeyMenu/SceneKeyMenu.cpp
        src/Scenes/SceneKeyMenu/SceneKeyMenu.hpp
        src/Scenes/SceneCharacterMenu/SceneCharacterMenu.cpp
        src/Scenes/SceneCharacterMenu/SceneCharacterMenu.hpp
        src/Scenes/SceneLauncher.cpp
        src/Scenes/SceneLauncher.hpp

        src/AnimatedObject.cpp
        src/AnimatedObject.hpp
        src/AObject.cpp
        src/AObject.hpp
        src/LightObject.cpp
        src/LightObject.hpp
        src/StaticObject.cpp
        src/StaticObject.hpp
        src/Version.cpp
        src/Version.hpp
        src/CameraObject.cpp
        src/CameraObject.hpp
        src/PlaneObject.cpp
        src/PlaneObject.hpp
        src/BillboardObject.cpp
        src/BillboardObject.hpp

        src/Xml/XmlWriter.cpp
        src/Xml/XmlWriter.hpp
        src/Xml/XmlReader.cpp
        src/Xml/XmlReader.hpp
        )

        add_executable(bombermario WIN32
        ${SRC_FILES}
        ${SRC_RESOURCES}
        src/BomberMario.cpp)

        target_link_libraries(bombermario Irrlicht ${LIBOPENAL_NAME} ${LIBVORBISFILE_NAME} ${LIBEXTRA_NAME})

        if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
        add_custom_command(TARGET bombermario POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:bombermario> ${CMAKE_SOURCE_DIR}/bomberman)
        elseif("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
        set_target_properties(bombermario PROPERTIES LINK_FLAGS "/ENTRY:mainCRTStartup")
        add_custom_command(TARGET bombermario POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:bombermario> ${CMAKE_SOURCE_DIR}/win/bombermario.exe)
        endif()

        install(TARGETS bombermario DESTINATION /usr/bin/ CONFIGURATIONS Release)
        install(DIRECTORY assets/ DESTINATION /usr/share/bombermario CONFIGURATIONS Release)
