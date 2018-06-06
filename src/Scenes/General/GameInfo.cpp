/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
** GameInfo.cpp
*/

#include "GameInfo.hpp"

void bomb::game::GameInfo::createMap(IAssetLoader &loader,
				     irr::video::ITexture *texture)
{
	bomb::MapConstructor pattern = MapGenerator(15).generate();

	pattern.dumpMap();
	_characters[SHYGUY_BLACK] = loader.createAnimatedObject(
		"models/characters/shyGuy/shyGuyBlack.obj");
	_characters[SHYGUY_BLUE] = loader.createAnimatedObject(
		"models/characters/shyGuy/shyGuyBlue.obj");
	_characters[SHYGUY_RED] = loader.createAnimatedObject(
		"models/characters/shyGuy/shyGuyRed.obj");
	_characters[SHYGUY_WHITE] = loader.createAnimatedObject(
		"models/characters/shyGuy/shyGuyWhite.obj");
	_characters[SKELEREX] = loader.createAnimatedObject(
		"models/characters/skelerex/skelerex.obj");
	_mapSize = pattern.getSize();
	_characters[SHYGUY_BLACK]->setPos({-1, 0, -1});
	_characters.at(SKELEREX)->setVisible(false);
	_map = std::move(pattern.construct(loader, { 0, 0, 0 },
					   { 1, 1, 1 }, { 0, 0, 0 }));
	_map->setTextures(texture);
	loader.createLightObject({(float)pattern.getSize() / 2,
				  (float)pattern.getSize() / 2,
				  (float)pattern.getSize() / 2},
				 {1, 1, 1}, pattern.getSize());
	reset();
}

void bomb::game::GameInfo::reset()
{
	_players[0].setCharacterIndex(SHYGUY_BLACK);
	_players[1].setCharacterIndex(SHYGUY_BLUE);
	_players[2].setCharacterIndex(SHYGUY_RED);
	_players[3].setCharacterIndex(SHYGUY_WHITE);
}


int bomb::game::GameInfo::getMapSize() const
{
	return _mapSize;
}
