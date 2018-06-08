//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// SceneLauncher.cpp
//

#include "SceneGame.hpp"

bomb::scene::SceneGame::SceneGame(bomb::PersistentInfo &_infos) :
	AScene(_infos) {}

bomb::scene::SceneStatus bomb::scene::SceneGame::start(IAssetLoader &loader)
{
	_blocksTextures = loader.loadTexture("models/blocks/spritesheet.png");
	_game.createGame(loader, _blocksTextures);
	auto cam = loader.getCamera();
	float mid = (float)(_game.getMapSize() - 1) / 2;
	cam->setPos({mid, (float)_game.getMapSize() * 0.8f,
		(float)_game.getMapSize() * 0.8f});
	cam->setTarget({mid, 0, mid + 1});
	return BEGIN;
}

bomb::scene::SceneStatus bomb::scene::SceneGame::loop(
	bomb::IAssetLoader &loader)
{
	explodeBombs(loader);
	_game.execute(loader);
	return CONTINUE;
}

void bomb::scene::SceneGame::explodeBombs(bomb::IAssetLoader &loader)
{
	for (auto &bomb : _bombs)
		bomb.get()->tryToActivate(*_game.getMap(),
		_game.getPlayers());
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
		return _game.handleEvent(event);
	return true;
}
