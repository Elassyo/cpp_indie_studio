//
// EPITECH PROJECT, 2018
// cpp_indie_studio - SpeedUp.cpp
// File description:
// Created by Gregory EPLE
//

#include "SpeedUp.hpp"

bomb::object::SpeedUp::SpeedUp(bomb::IAssetManager &loader,
	const irr::core::vector3df &pos) :
	Power(loader, pos, "models/powers/speeds/speedUp.obj")
{
}

bool bomb::object::SpeedUp::activate(bomb::Map &map, bomb::game::Player &player)
{
	if (player.getSpeed() < 1.0f)
		player.setSpeed(player.getSpeed() + 0.05f);
	return Power::activate(map, player);
}
