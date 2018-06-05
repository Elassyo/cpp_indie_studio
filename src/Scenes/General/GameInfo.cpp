/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
** GameInfo.cpp
*/

#include "GameInfo.hpp"

bomb::game::GameInfo::GameInfo(bomb::IAssetLoader &loader) :
	_loader(loader), _mapGenerator(10)
{
	_characters[SHYGUY_BLACK] = loader.createAnimatedObject(
		"assets/models/characters/shyGuy/shyGuyBlack.obj");
	_characters[SHYGUY_BLUE] = loader.createAnimatedObject(
		"assets/models/characters/shyGuy/shyGuyBlue.obj");
	_characters[SHYGUY_RED] = loader.createAnimatedObject(
		"assets/models/characters/shyGuy/shyGuyRed.obj");
	_characters[SHYGUY_WHITE] = loader.createAnimatedObject(
		"assets/models/characters/shyGuy/shyGuyWhite.obj");
	_characters[SKELEREX] = loader.createAnimatedObject(
		"assets/models/characters/skelerex/skelerex.obj");
	createMap(loader);
	reset();
}

void bomb::game::GameInfo::createMap(IAssetLoader &loader)
{
	bomb::MapConstructor pattern = _mapGenerator.generate();

	pattern.dumpMap();
	_map = std::move(pattern.construct(loader,
		{0, 0, 0}, {10, 10, 1}, {0, 0, 0}));
}

void bomb::game::GameInfo::reset()
{
	_players[0].setCharacterIndex(SHYGUY_BLACK);
	_players[1].setCharacterIndex(SHYGUY_BLUE);
	_players[2].setCharacterIndex(SHYGUY_RED);
	_players[3].setCharacterIndex(SHYGUY_WHITE);
}
