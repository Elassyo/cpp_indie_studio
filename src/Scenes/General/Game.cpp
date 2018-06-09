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
	reset();
	(void) texture;
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
	executePlayers(loader);
	executeBombs(loader);
}

void bomb::game::Game::executePlayers(bomb::IAssetLoader &loader)
{
	for (auto i = 0; i < NB_PLAYERS; ++i) {
		if (!_players[i].first.isAlive())
			continue;
		_players[i].first.execute(*_map);
		_players[i].second.actionnate(*_map, _players[i].first);
		if (_players[i].first.isBombReady()) {
			_bombs.emplace_back(new bomb::object::Bomb
				(loader, _players[i].first, i));
			_players[i].first.setBombReady(false);
		}
	}

}

void bomb::game::Game::executeBombs(bomb::IAssetLoader &loader)
{
	auto bomb = _bombs.begin();
	while (bomb != _bombs.end()) {
		if ((*bomb)->tryToActivate(*_map, _players)) {
			auto blast = (*bomb)->getBlast();
			_map->updateFromCells(loader);
			killPlayersInBlast(blast, loader);
			bomb = _bombs.erase(bomb);
		} else
			bomb++;
	}
}

void bomb::game::Game::killPlayersInBlast(
	std::vector<irr::core::vector2di> &blast,
	bomb::IAssetLoader &loader)
{
	for (auto &p : _players) {
		if (!p.first.isAlive())
			continue;
		for (auto b : blast) {
			irr::core::vector2di pos(
				static_cast<irr::s32>(p.first.getExactPos().X),
				static_cast<irr::s32>(p.first.getExactPos().Z));
			if (pos == b) {
				p.first.setAlive(false, loader);
				break;
			}
		}
	}
}

bool bomb::game::Game::handleEvent(const irr::SEvent &event)
{
	for (auto &p : _players) {
		if (p.first.isAI() || !p.first.isAlive())
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
