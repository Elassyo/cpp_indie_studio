//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// GameScene.cpp
//

#include "GameScene.hpp"

bomb::scene::GameScene::GameScene(bomb::GameEngine &gameEngine) :
	_gameEngine(gameEngine)
{
	gameEngine.addCamera({0, 0, 0}, {0, 0, 0});
}

void bomb::scene::GameScene::gameLoop()
{
	while (1) {
		_gameEngine.refresh();
	}
}
