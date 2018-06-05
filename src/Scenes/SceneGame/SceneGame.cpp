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
	_blocksTextures = loader.loadTexture
		("assets/models/blocks/spritesheet.png");
	_gameInfo.createMap(loader, _blocksTextures);
	loader.addCamera(irr::core::vector3df(((float)_gameInfo.getMapSize())/2,
					10, ((float)_gameInfo.getMapSize())/2),
			irr::core::vector3df(_gameInfo.getMapSize()/2, 0,
					_gameInfo.getMapSize()/2));

	return BEGIN;
}

bomb::scene::SceneStatus
bomb::scene::SceneGame::loop(bomb::IAssetLoader &loader)
{
	explodeBombs(loader);
	return CONTINUE;
}

void bomb::scene::SceneGame::explodeBombs(
	__attribute__((unused))bomb::IAssetLoader &loader)
{
	for (auto &bomb : _bombs)
		bomb.get()->tryToActivate(_gameInfo);
}

void bomb::scene::SceneGame::save()
{
}

void bomb::scene::SceneGame::reset(__attribute__((unused))
				bomb::IAssetLoader &loader)
{
}

void bomb::scene::SceneGame::clean()
{
}

std::string bomb::scene::SceneGame::nextScene()
{
	return std::__cxx11::string();
}

bool bomb::scene::SceneGame::onEvent(__attribute__((unused))
				const irr::SEvent &event)
{
	return true;
}
