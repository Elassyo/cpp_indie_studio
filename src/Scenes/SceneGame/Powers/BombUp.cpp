//
// EPITECH PROJECT, 2018
// cpp_indie_studio - BombUp.cpp
// File description:
// Created by Gregory EPLE
//

#include "BombUp.hpp"

bomb::object::BombUp::BombUp(bomb::IAssetManager &loader,
	const irr::core::vector3df &pos) :
	Power(loader, pos, "models/powers/bombs/bombUp.obj")
{
}

bool bomb::object::BombUp::activate(bomb::Map &map, bomb::game::Player &player)
{
	if (player.getNbBombs() < 99)
		player.setNbBombs(player.getNbBombs() + 1);
	return Power::activate(map, player);
}
