//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// SceneLauncher.cpp
//

#include "SceneGame.hpp"

bomb::scene::SceneStatus bomb::scene::SceneGame::start(IAssetLoader &loader)
{
	_blocksTextures = loader.loadTexture("assets/models/blocks/spritesheet.png");
	loader.getStaticObject("assets/models/blocks/brick.obj", {0, 0, 0},
				{0, 0, 0})->setTexture(0, _blocksTextures);
	loader.addCamera(irr::core::vector3df(0, 30, -40),
			irr::core::vector3df(0, 5, 0));
	return BEGIN;
}

bomb::scene::SceneStatus
bomb::scene::SceneGame::loop(__attribute__((unused))bomb::IAssetLoader &loader)
{
	return CONTINUE;
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
