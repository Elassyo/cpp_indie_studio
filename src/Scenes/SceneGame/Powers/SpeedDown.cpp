//
// EPITECH PROJECT, 2018
// cpp_indie_studio - SpeedDown.cpp
// File description:
// Created by Gregory EPLE
//

#include "SpeedDown.hpp"

bomb::object::SpeedDown::SpeedDown(bomb::IAssetLoader &loader,
	const irr::core::vector3df &pos) :
	Power(loader, pos, "models/powers/speeds/speedDown.obj")
{
}

bool bomb::object::SpeedDown::activate(bomb::Map &map, bomb::game::Player &player)
{
	if (player.getSpeed() > 0.05f)
		player.setSpeed(player.getSpeed() - 0.05f);
	return Power::activate(map, player);
}
