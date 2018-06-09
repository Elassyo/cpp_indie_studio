//
// EPITECH PROJECT, 2018
// cpp_indie_studio - BombFull.cpp
// File description:
// Created by Gregory EPLE
//

#include "BombFull.hpp"

bomb::object::BombFull::BombFull(bomb::IAssetManager &loader,
	const irr::core::vector3df &pos) :
	Power(loader, pos, "models/powers/bombs/bombFull.obj")
{
}

bool bomb::object::BombFull::activate(bomb::Map &map,
		bomb::game::Player &player)
{
	player.setNbBombs(99);
	return Power::activate(map, player);
}
