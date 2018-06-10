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

void bomb::object::SpeedUp::addPower(bomb::game::Player &player)
{
	if (player.getSpeed() < 0.5f)
		player.setSpeed(player.getSpeed() + 0.01f);
}
