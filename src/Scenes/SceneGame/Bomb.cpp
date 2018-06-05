//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// Bomb.cpp
//

#include "Bomb.hpp"

bomb::object::Bomb::Bomb(
	bomb::IAssetLoader &loader, const irr::core::vector3df &pos,
	const long time) : loader(loader), _timer(time),
	_model(loader.createAnimatedObject("assets/models/bob-bomb.x", pos))
{
}

bool bomb::object::Bomb::isActivable(
	__attribute__((unused))bomb::game::GameInfo &infos)
{
	return _timer.isReady();
}

bool bomb::object::Bomb::activate(
	__attribute__((unused))bomb::game::GameInfo &infos)
{
	loader.deleteObject(std::move(_model));
	return true;
}

void
bomb::object::Bomb::setProperties(
	__attribute__((unused))bomb::game::GameInfo &infos,
	__attribute__((unused))uint8_t idx)
{

}