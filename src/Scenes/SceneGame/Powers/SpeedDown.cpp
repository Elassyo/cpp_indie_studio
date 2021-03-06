//
// EPITECH PROJECT, 2018
// cpp_indie_studio - SpeedDown.cpp
// File description:
// Created by Gregory EPLE
//

#include "SpeedDown.hpp"

bomb::object::SpeedDown::SpeedDown(bomb::IAssetManager &loader,
	const irr::core::vector3df &pos) :
	Power(loader, pos, "models/powers/speeds/speedDown.obj")
{
}

void bomb::object::SpeedDown::addPower(bomb::game::Player &player)
{
	if (player.getSpeed() > 0.05f)
		player.setSpeed(player.getSpeed() - 0.01f);
}
