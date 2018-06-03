//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// SceneLauncher.cpp
//

#include "SceneGame.hpp"

bomb::scene::SceneStatus bomb::scene::SceneGame::start(IAssetLoader &loader)
{
	loader.getAnimatedObject("assets/models/bob-bomb.x", {0, 0, 0},
				{0, 0, 0});
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

void bomb::scene::SceneGame::reset(
	__attribute__((unused))bomb::IAssetLoader &loader)
{
}

void bomb::scene::SceneGame::clean()
{
}

std::string bomb::scene::SceneGame::nextScene()
{
	return std::__cxx11::string();
}
