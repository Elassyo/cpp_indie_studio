//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// Bomb.cpp
//

#include "Bomb.hpp"

bomb::object::Bomb::Bomb(bomb::IAssetLoader &loader,
	const irr::core::vector3df &pos, const long time) :
	_loader(loader), _timer(time),
	_model(loader.createAnimatedObject("models/bob-bomb.x", pos))
{
}

bool bomb::object::Bomb::isActivable(bomb::Map &map,
				     std::vector<game::Player> &player)
{
	return _timer.isReady();
	(void) map;
	(void) player;
}

bool bomb::object::Bomb::activate(bomb::Map &map,
				  std::vector<game::Player> &player)
{
	_loader.deleteObject(std::move(_model));
	return true;
	(void) map;
	(void) player;
}

void bomb::object::Bomb::setProperties(bomb::game::Game &infos, char idx)
{
	(void) infos;
	(void) idx;
}
