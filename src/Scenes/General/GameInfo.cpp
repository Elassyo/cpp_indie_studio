/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
** GameInfo.cpp
*/

#include "GameInfo.hpp"
#include "../../Exception/Exception.hpp"

void bomb::game::GameInfo::createGame(IAssetLoader &loader,
	irr::video::ITexture *texture)
{
	createMap(loader, MAP_SIZE);
	createPlayers(loader, "models/characters/shyGuy/shyGuyBlack.obj", SHYGUY_BLACK, {1, 0, 1});
	createPlayers(loader, "models/characters/shyGuy/shyGuyBlue.obj", SHYGUY_BLUE, {1, 0, MAP_SIZE - 2});
	createPlayers(loader, "models/characters/shyGuy/shyGuyRed.obj", SHYGUY_RED, {MAP_SIZE - 2, 0, 1});
	createPlayers(loader, "models/characters/shyGuy/shyGuyWhite.obj", SHYGUY_WHITE, {MAP_SIZE - 2, 0, MAP_SIZE - 2});
	//createPlayers(loader, "models/characters/skelerex/skelerex.obj", SKELEREX, {0, 0, 0});
	_map->setTextures(texture);
	reset();
}

void bomb::game::GameInfo::createMap(
	bomb::IAssetLoader &loader, unsigned int size)
{
	bomb::MapConstructor pattern = MapGenerator(size).generate();
	pattern.dumpMap();

	_mapSize = pattern.getSize();
	_map = std::move(pattern.construct(loader, {0, 0, 0},
		{1, 1, 1}, {0, 0, 0}));
	loader.createLightObject({(float)pattern.getSize() / 2,
			(float)pattern.getSize() / 2,
			(float)pattern.getSize() / 2},
		{1, 1, 1}, pattern.getSize());
}

void bomb::game::GameInfo::createPlayers(
	bomb::IAssetLoader &loader,
	const std::string &path,
	Character index,
	const irr::core::vector3di &spawn)
{
	if (_players.size() >= NB_PLAYERS)
		throw bomb::Exception("GameCreation", "Too much players");
	/* A CHANGER ! ECHELLES DE TAILLE */
	_players.push_back(bomb::game::PlayerInfo(loader, path,
		{spawn.X, spawn.Y, spawn.Z}, {1, 1, 1}, {0, 0, 0}, spawn));
	_players[_players.size() - 1].setCharacterIndex(index);
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
