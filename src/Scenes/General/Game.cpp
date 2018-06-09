/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
** Game.cpp
*/

#include "Game.hpp"

bomb::game::Game::Game(bomb::PersistentInfo &infos) :
	_infos(infos), _charLoader()
{
}

void bomb::game::Game::createGame(IAssetLoader &loader,
				  irr::video::ITexture *texture)
{
	createMap(loader, MAP_SIZE);
	for (int i = 0; i < 4; ++i)
		createPlayer(loader, _charLoader.getCharacterPath(
			_infos.getPlayerInfos(i).getCharacter()),
			     std::make_unique<bomb::player::AIController>(_map),
			     {i % 2 ? 1 : MAP_SIZE - 2, 0,
			      i > 1 ? MAP_SIZE - 2 : 1});
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
			(float)pattern.getSize(),
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
	for (auto i = 0; i < NB_PLAYERS; ++i) {
		_players[i].first.execute(*_map);
		_players[i].second.actionnate(*_map, _players[i].first);
		if (_players[i].first.isBombReady()) {
			_bombs.emplace_back(loader, _players[i].first, i);
			_players[i].first.setBombReady(false);
		}
	}
	for (auto &b : _bombs) {
		if (b.tryToActivate(*_map, _players)) {
			_map->updateFromCells(loader);
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

