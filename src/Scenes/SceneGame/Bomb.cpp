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
	_loader(loader),
	_model(loader.createAnimatedObject(
	"models/bob-bomb.x", player.getExactPos(), {.5, .5, .5})),
	_timer(2000), _playerIdx(playerIdx)
{

}

bool bomb::object::Bomb::deleteBlock(bomb::Map &map, irr::core::vector3df pos)
{
	if (map[pos] != Map::BREAKABLE)
		return map[pos] != Map::EMPTY;
	map[pos] = Map::EMPTY;
	_blast.emplace_back((float)pos.X, (float)pos.Z);
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

bomb::IAssetLoader &bomb::object::Bomb::getLoader() const
{
	return _loader;
}

void bomb::object::Bomb::setLoader(bomb::IAssetLoader &_loader)
{
	Bomb::_loader = _loader;
}

const std::unique_ptr<bomb::AnimatedObject> &bomb::object::Bomb::getModel()
const
{
	return _model;
}

void bomb::object::Bomb::setModel(std::unique_ptr<AnimatedObject> &_model)
{
	Bomb::_model = std::move(_model);
}

const std::vector<irr::core::vector2di> &bomb::object::Bomb::getBlast() const
{
	return _blast;
}

void
bomb::object::Bomb::setBlast(const std::vector<irr::core::vector2di> &_blast)
{
	Bomb::_blast = _blast;
}

const bomb::utils::Clock &bomb::object::Bomb::getTimer() const
{
	return _timer;
}

void bomb::object::Bomb::setTimer(const bomb::utils::Clock &_timer)
{
	Bomb::_timer = _timer;
}

int bomb::object::Bomb::getPlayerIdx() const
{
	return _playerIdx;
}

void bomb::object::Bomb::setPlayerIdx(int _playerIdx)
{
	Bomb::_playerIdx = _playerIdx;
}

bomb::object::Bomb::Bomb(const bomb::object::Bomb &bomb) :
	_loader(bomb.getLoader()),
	_blast(bomb.getBlast()),
	_timer(bomb.getTimer()),
	_playerIdx(bomb.getPlayerIdx())
{
}
