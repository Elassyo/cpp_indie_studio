//
// EPITECH PROJECT, 2018
// cpp_indie_studio - FireFull.cpp
// File description:
// Created by Gregory EPLE
//

#include "FireFull.hpp"

bomb::object::FireFull::FireFull(bomb::IAssetLoader &loader,
				 const irr::core::vector3df &pos) :
	Power(loader, pos, "models/powers/fires/fireFull.obj")
{
}

bool bomb::object::FireFull::activate(bomb::game::Game &infos)
{
	return Power::activate(infos);
}
