//
// EPITECH PROJECT, 2018
// cpp_indie_studio - Power.cpp
// File description:
// Created by Gregory EPLE
//

#include "Power.hpp"

bomb::object::Power::Power(bomb::IAssetManager &loader,
	const irr::core::vector3df &pos, std::string path) :
	_loader(loader),
	_model(loader.createStaticObject(path, pos, {.5, .5, .5})),
	_killed(false)
{
}

bool bomb::object::Power::activate(bomb::Map &map, bomb::game::Player &player)
{
	destroy(_loader);
	return true;
	(void) map;
	(void) player;
}

int bomb::object::Power::isActivable(bomb::Map &map,
	std::vector<std::pair<bomb::game::Player,
	bomb::PlayerActionner>> &vector)
{
	auto pos = _model->getPos();
	for (unsigned int i = 0; i < vector.size(); ++i) {
		if (!vector[i].first.isAlive())
			continue;
		auto playerPos = vector[i].first.getExactPos();
		if ((int)playerPos.X == (int)pos.X
		    && (int)playerPos.Z == (int)pos.Z)
			return i;
	}
	return -1;
	(void) map;
}

irr::core::position2di bomb::object::Power::getPos()
{
	if (_model == nullptr)
		return {-1, -1};
	return {static_cast<irr::s32>(_model->getPos().X),
		static_cast<irr::s32>(_model->getPos().Z)};
}

void bomb::object::Power::destroy(bomb::IAssetManager &manager)
{
	if (_model != nullptr)
		manager.deleteObject(std::move(_model));
	_killed = true;
}

bool bomb::object::Power::isKilled()
{
	return _killed;
}