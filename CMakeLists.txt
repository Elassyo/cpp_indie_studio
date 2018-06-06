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
        src/Scenes/SceneLauncher.cpp
        src/Scenes/SceneLauncher.hpp

        src/AnimatedObject.cpp
        src/AnimatedObject.hpp
        src/AObject.cpp
        src/AObject.hpp
        src/StaticObject.cpp
        src/StaticObject.hpp
        src/Version.cpp
        src/Version.hpp
        )

add_executable(bombermario WIN32
        ${SRC_FILES}
        ${SRC_RESOURCES}
        src/BomberMario.cpp)

add_executable(test_menu
        ${SRC_FILES}
        tests/MenuPreview.cpp)

add_executable(tests_map_gen
        ${SRC_FILES}
        tests/MapGen.cpp)

target_link_libraries(tests_map_gen Irrlicht ${LIBOPENAL_NAME} ${LIBVORBISFILE_NAME} ${LIBEXTRA_NAME})

target_link_libraries(test_menu Irrlicht ${LIBOPENAL_NAME} ${LIBVORBISFILE_NAME} ${LIBEXTRA_NAME})

target_link_libraries(bombermario Irrlicht ${LIBOPENAL_NAME} ${LIBVORBISFILE_NAME} ${LIBEXTRA_NAME})

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
    add_custom_command(TARGET bombermario POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:bombermario> ${CMAKE_SOURCE_DIR}/bomberman)
elseif("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
	set_target_properties(bombermario PROPERTIES LINK_FLAGS "/ENTRY:mainCRTStartup")
    add_custom_command(TARGET bombermario POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:bombermario> ${CMAKE_SOURCE_DIR}/win/bombermario.exe)
endif()

install(TARGETS bombermario DESTINATION /usr/bin/ CONFIGURATIONS Release)
install(DIRECTORY assets/ DESTINATION /usr/share/bombermario CONFIGURATIONS Release)
