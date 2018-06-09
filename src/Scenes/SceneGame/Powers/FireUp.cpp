//
// EPITECH PROJECT, 2018
// cpp_indie_studio - FireUp.cpp
// File description:
// Created by Gregory EPLE
//

#include "FireUp.hpp"

bomb::object::FireUp::FireUp(bomb::IAssetLoader &loader,
	const irr::core::vector3df &pos) :
	Power(loader, pos, "models/powers/fires/fireUp.obj")
{
}

bool bomb::object::FireUp::activate(bomb::Map &map, bomb::game::Player &player)
{
	if (player.getBombRange() < 99)
		player.setBombRange(player.getBombRange() + 1);
	return Power::activate(map, player);
}
