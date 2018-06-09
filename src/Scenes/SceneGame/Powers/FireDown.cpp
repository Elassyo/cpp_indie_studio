//
// EPITECH PROJECT, 2018
// cpp_indie_studio - FireDown.cpp
// File description:
// Created by Gregory EPLE
//

#include "FireDown.hpp"

bomb::object::FireDown::FireDown(bomb::IAssetManager &loader,
	const irr::core::vector3df &pos) :
	Power(loader, pos, "models/powers/fires/fireDown.obj")
{
}

void bomb::object::FireDown::addPower(bomb::game::Player &player)
{
	if (player.getBombRange() > 1)
		player.setBombRange(player.getBombRange() - 1);
}
