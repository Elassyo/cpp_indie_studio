//
// EPITECH PROJECT, 2018
// cpp_indie_studio - FireFull.cpp
// File description:
// Created by Gregory EPLE
//

#include "FireFull.hpp"

bomb::object::FireFull::FireFull(bomb::IAssetManager &loader,
				 const irr::core::vector3df &pos) :
	Power(loader, pos, "models/powers/fires/fireFull.obj")
{
}

void bomb::object::FireFull::addPower(bomb::game::Player &player)
{
	player.setBombRange(99);
}
