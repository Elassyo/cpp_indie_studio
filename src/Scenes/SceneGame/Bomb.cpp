//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// Bomb.cpp
//

#include "Bomb.hpp"

bomb::object::Bomb::Bomb(bomb::IAssetLoader &loader,
			 bomb::game::Player &player,
			int playerIdx) :
	_loader(loader), _timer(2000),
	_model(loader.createAnimatedObject("models/bob-bomb.x",
		player.getExactPos(), {.5, .5, .5})),
	_playerIdx(playerIdx)
{

}

bool bomb::object::Bomb::deleteBlock(bomb::Map &map, irr::core::vector3df pos)
{
	if (map[pos] != Map::BREAKABLE)
		return false;
	map[pos] = Map::EMPTY;
	return true;
}

bool bomb::object::Bomb::activate(bomb::Map &map, bomb::game::Player &player)
{
	auto pos = _model->getPos();
	map[pos] = Map::EMPTY;
	_loader.deleteObject(std::move(_model));
	player.setNbBombs(static_cast<uint8_t>(player.getNbBombs() + 1));
	for (auto i = 1; i <= player.getBombRange(); ++i) {
		if (pos.X + 1 < map.getSize())
			deleteBlock(map, {pos.X + 1, pos.Y, pos.Z});
		if (pos.X - 1 >= 0)
			deleteBlock(map, {pos.X - 1, pos.Y, pos.Z});
		if (pos.Z + 1 < map.getSize())
			deleteBlock(map, {pos.X, pos.Y, pos.Z + 1});
		if (pos.Z - 1 >= 0)
			deleteBlock(map, {pos.X, pos.Y, pos.Z - 1});
	}
	return true;
}

int bomb::object::Bomb::isActivable(bomb::Map &map,
	std::vector<std::pair<bomb::game::Player,
		bomb::PlayerActionner>> &player)
{
	if (_timer.isReady())
		return _playerIdx;
	return -1;
	(void) map;
	(void) player;
}