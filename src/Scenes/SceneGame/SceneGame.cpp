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
	loader.getStaticObject("assets/models/blocks/brick.obj", {0, 0, 0},
			       {0, 0, 0})
		->setTexture(0, _blocksTextures);
	loader.getStaticObject("assets/models/blocks/brick.obj", {0, 2, 0},
			       {0, 0, 0}, {0.1, 0.1, 0.1})
		->setTexture(0, _blocksTextures);
	loader.addCamera(irr::core::vector3df(0, 10, -20),
			irr::core::vector3df(0, 5, 5));
	_bombs.emplace_back(std::make_unique<bomb::object::Bomb>
	        (bomb::object::Bomb(loader, {0, 0, 0}, 3000)));
	//
	return BEGIN;
}

bomb::scene::SceneStatus
bomb::scene::SceneGame::loop(__attribute__((unused))bomb::IAssetLoader &loader)
{
	explodeBombs();
	return CONTINUE;
}

void bomb::scene::SceneGame::explodeBombs()
{
	//Temporary
	bomb::game::GameInfo i;bomb::Map m;

	for (auto &bomb : _bombs)
		bomb.get()->tryToActivate(i, m);
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

bool bomb::scene::SceneGame::onEvent(__attribute__((unused))const irr::SEvent
&event)
{
	return true;
}
