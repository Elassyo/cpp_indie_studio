//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// Bomb.cpp
//

#include "Bomb.hpp"

bomb::object::Bomb::Bomb(bomb::IAssetLoader &loader,
			 bomb::game::Player &player) :
	_loader(loader), _timer(2000),
	_model(loader.createAnimatedObject("models/bob-bomb.x",
		player.getExactPos())),
	_playerIdx(0)
{

}

bool bomb::object::Bomb::activate(bomb::Map &map, bomb::game::Player &player)
{
	_loader.deleteObject(std::move(_model));
	return true;
	(void) map;
	(void) player;
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