/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
** Game.cpp
*/

#include "Game.hpp"

bomb::game::Game::Game(bomb::PersistentInfo &infos) : _infos(infos)
{
}

void bomb::game::Game::createGame(IAssetLoader &loader,
	irr::video::ITexture *texture)
{
	createMap(loader, MAP_SIZE);

	/* TEMPORALY */
	createPlayer(loader, "models/characters/shyGuy/shyGuyBlack.obj",
		std::make_unique<bomb::player::AIController>(_map),
		{1, 0, 1});
	createPlayer(loader, "models/characters/shyGuy/shyGuyBlue.obj",
		std::make_unique<bomb::player::AIController>(_map),
		{1, 0, MAP_SIZE - 2});
	createPlayer(loader, "models/characters/shyGuy/shyGuyRed.obj",
		std::make_unique<bomb::player::AIController>(_map),
		{MAP_SIZE - 2, 0, 1});
	createPlayer(loader, "models/characters/shyGuy/shyGuyWhite.obj",
		std::make_unique<bomb::player::AIController>(_map),
		{MAP_SIZE - 2, 0, MAP_SIZE - 2});
	_map->setTextures(texture);
	reset();
}

void bomb::game::Game::createMap(
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

void bomb::game::Game::createPlayer(bomb::IAssetLoader &loader,
	const std::string &path,
	std::unique_ptr<bomb::IPlayerController> controller,
	const irr::core::vector3di &spawn)
{
	if (_players.size() >= NB_PLAYERS)
		throw bomb::Exception("GameCreation", "Too much players");

	/* A CHANGER ! ECHELLES DE TAILLE */
	_players.push_back({bomb::game::Player(loader, path, controller,
		{(float)spawn.X, (float)spawn.Y, (float)spawn.Z},
		{.5, .5, .5}, {0, 0, 0},
		_infos.getPlayerInfos()[_players.size()]), {true}});
}

void bomb::game::Game::reset()
{
}


int bomb::game::Game::getMapSize() const
{
	return _mapSize;
}

void bomb::game::Game::execute(bomb::IAssetLoader &loader)
{
	for (auto &p : _players) {
		p.first.execute(*_map);
		p.second.actionnate(*_map, p.first);
		if (p.first.isBombReady()) {
			_bombs.emplace_back(std::make_unique<object::Bomb>
			(loader, p.first));
		}
	}
}

bool bomb::game::Game::handleEvent(const irr::SEvent &event)
{
	//Check if keyEvent is in player keyset and call his handleEvent method
	for (auto &p : _players) {
		if (p.first.isAI())
			continue;
		auto action = p.first.getActionFromEvent(event);
		if (action != IPlayerController::UNDEFINED) {
			if (event.KeyInput.PressedDown)
				p.second.sendAction(*_map, p.first, action);
			else
				p.second.removeAction(action);
		}
	}
	return true;
}

std::vector<std::pair<bomb::game::Player, bomb::PlayerActionner>> &
bomb::game::Game::getPlayers()
{
	return _players;
}

std::shared_ptr<bomb::Map> &bomb::game::Game::getMap()
{
	return _map;
}

