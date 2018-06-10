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

bool bomb::object::Power::activate(bomb::BomberMap &map,
				bomb::game::Player &player,
				IAssetManager &loader)
{
	addPower(player);
	destroy(loader);
	return true;
	(void) map;
}

void bomb::object::Power::addPower(bomb::game::Player &player)
{
	(void) player;
}

int bomb::object::Power::isActivable(bomb::BomberMap &map,
				     std::array<bomb::game::Player, 4> &vector)
{
	auto pos = _model->getPos();
	for (unsigned int i = 0; i < vector.size(); ++i) {
		if (!vector[i].isAlive())
			continue;
		auto playerPos = vector[i].getExactPos();
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
}