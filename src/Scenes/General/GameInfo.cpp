/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
** GameInfo.cpp
*/

#include "GameInfo.hpp"
#include "../../Exception/Exception.hpp"
#include "../../Player/AIController.hpp"

void bomb::game::GameInfo::createGame(IAssetLoader &loader,
	irr::video::ITexture *texture)
{
	createMap(loader, MAP_SIZE);

	/* TEMPORALY */
	createPlayer(loader, "models/characters/shyGuy/shyGuyBlack.obj",
		std::make_unique<bomb::player::AIController>(), SHYGUY_BLACK,
		{1, 0, 1});
	createPlayer(loader, "models/characters/shyGuy/shyGuyBlue.obj",
		std::make_unique<bomb::player::AIController>(), SHYGUY_BLUE,
		{1, 0, MAP_SIZE - 2});
	createPlayer(loader, "models/characters/shyGuy/shyGuyRed.obj",
		std::make_unique<bomb::player::AIController>(), SHYGUY_RED,
		{MAP_SIZE - 2, 0, 1});
	createPlayer(loader, "models/characters/shyGuy/shyGuyWhite.obj",
		std::make_unique<bomb::player::AIController>(), SHYGUY_WHITE,
		{MAP_SIZE - 2, 0, MAP_SIZE - 2});
	//createPlayer(loader, "models/characters/skelerex/skelerex.obj", SKELEREX, {0, 0, 0});
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

void bomb::game::GameInfo::createPlayer(bomb::IAssetLoader &loader,
	const std::string &path,
	std::unique_ptr<bomb::IPlayerController> controller,
	Character index, const irr::core::vector3di &spawn)
{
	if (_players.size() >= NB_PLAYERS)
		throw bomb::Exception("GameCreation", "Too much players");

	/* A CHANGER ! ECHELLES DE TAILLE */
	_players.push_back(bomb::game::Player(loader, path, controller,
		{(float)spawn.X, (float)spawn.Y, (float)spawn.Z},
		{.5, .5, .5}, {0, 0, 0}));
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

void bomb::game::GameInfo::executePlayers()
{
	for (auto &p : _players) {
		p.execute();
	}
}
