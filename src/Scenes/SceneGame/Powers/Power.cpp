//
// EPITECH PROJECT, 2018
// cpp_indie_studio - Power.cpp
// File description:
// Created by Gregory EPLE
//

#include "Power.hpp"

bomb::object::Power::Power(bomb::IAssetManager &loader,
	const irr::core::vector3df &pos, std::string path) :
	_model(loader.createStaticObject(path, pos, {.5, .5, .5}))
{
}

bool bomb::object::Power::activate(bomb::Map &map, bomb::game::Player &player,
				   IAssetManager &loader)
{
	addPower(player);
	loader.deleteObject(std::move(_model));
	return true;
	(void) map;
}

void bomb::object::Power::addPower(bomb::game::Player &player)
{
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
