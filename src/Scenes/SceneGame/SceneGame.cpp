//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// SceneLauncher.cpp
//

#include "SceneGame.hpp"

bomb::scene::SceneStatus bomb::scene::SceneGame::start(IAssetLoader &loader)
{
	//Testing loader (Temporary)
	_blocksTextures = loader.loadTexture("models/blocks/spritesheet.png");
	_gameInfo.createGame(loader, _blocksTextures);
	auto cam = loader.getCamera();
	cam->setPos({(float)_gameInfo.getMapSize() / 2, 30,
		     (float)_gameInfo.getMapSize()});
	cam->setRot({0, 200, 50});
	return BEGIN;
}

bomb::scene::SceneStatus bomb::scene::SceneGame::loop(
	bomb::IAssetLoader &loader)
{
	explodeBombs(loader);
	_gameInfo.executePlayers();
	return CONTINUE;
}

void bomb::scene::SceneGame::explodeBombs(bomb::IAssetLoader &loader)
{
	for (auto &bomb : _bombs)
		bomb.get()->tryToActivate(*_gameInfo.getMap(),
					  _gameInfo.getPlayers());
	(void) loader;
}

void bomb::scene::SceneGame::save()
{
}

void bomb::scene::SceneGame::reset(bomb::IAssetLoader &loader)
{
	(void) loader;
}

void bomb::scene::SceneGame::clean()
{
	delete _blocksTextures;
}

std::string bomb::scene::SceneGame::nextScene()
{
	return "";
}

bool bomb::scene::SceneGame::onEvent(const irr::SEvent &event)
{
	if (event.EventType == irr::EET_KEY_INPUT_EVENT)
		return _gameInfo.handleEvent(event);
	return true;
}
