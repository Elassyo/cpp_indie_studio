//
// EPITECH PROJECT, 2018
// cpp_indie_studio - BombDown.cpp
// File description:
// Created by Gregory EPLE
//

#include "BombDown.hpp"

bomb::object::BombDown::BombDown(bomb::IAssetManager &loader,
	const irr::core::vector3df &pos) :
	Power(loader, pos, "models/powers/bombs/bombDown.obj")
{
}

bool bomb::object::BombDown::activate(bomb::Map &map, bomb::game::Player &player)
{
	if (player.getNbBombs() > 1)
		player.setNbBombs(player.getNbBombs() - 1);
	return Power::activate(map, player);
}
