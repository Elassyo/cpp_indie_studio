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
	_blocksTextures = loader.loadTexture(
		"assets/models/blocks/spritesheet.png");
	loader.createStaticObject("assets/models/blocks/brick.obj", { 0, 0, 0 },
		{ 0, 0, 0 })
		->setTexture(0, _blocksTextures);
	loader.createStaticObject("assets/models/blocks/brick.obj", { 0, 2, 0 },
		{ 0, 0, 0 }, { 0.1f, 0.1f, 0.1f })->getPos();
	loader.addCamera(irr::core::vector3df(0, 10, -20),
		irr::core::vector3df(0, 5, 5));
	_bombs.emplace_back(std::make_unique<bomb::object::Bomb>
		(bomb::object::Bomb(loader, { 0, 0, 0 }, 3000)));
	//
	return BEGIN;
}

bomb::scene::SceneStatus bomb::scene::SceneGame::loop(
	bomb::IAssetLoader &loader)
{
	explodeBombs(loader);
	return CONTINUE;
}

void bomb::scene::SceneGame::explodeBombs(bomb::IAssetLoader &loader)
{
	//Temporary
	bomb::game::GameInfo i(loader);

	for (auto &bomb : _bombs)
		bomb.get()->tryToActivate(i);
}

void bomb::scene::SceneGame::save()
{
}

void bomb::scene::SceneGame::reset(bomb::IAssetLoader &loader)
{
}

void bomb::scene::SceneGame::clean()
{
}

std::string bomb::scene::SceneGame::nextScene()
{
	return "";
}

bool bomb::scene::SceneGame::onEvent(const irr::SEvent &event)
{
	return true;
}
