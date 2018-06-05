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
	_model(loader.createAnimatedObject("assets/models/bob-bomb.x", pos))
{
}

bool bomb::object::Bomb::isActivable(bomb::game::GameInfo &infos)
{
	return _timer.isReady();
}

bool bomb::object::Bomb::activate(bomb::game::GameInfo &infos)
{
	_loader.deleteObject(std::move(_model));
	return true;
}

void bomb::object::Bomb::setProperties(bomb::game::GameInfo &infos, uint8_t idx)
{
}
