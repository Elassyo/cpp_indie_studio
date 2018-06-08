//
// EPITECH PROJECT, 2018
// cpp_indie_studio - FireDown.cpp
// File description:
// Created by Gregory EPLE
//

#include "FireDown.hpp"

bomb::object::FireDown::FireDown(bomb::IAssetLoader &loader,
	const irr::core::vector3df &pos) :
	Power(loader, pos, "models/powers/fires/fireDown.obj")
{
}

bool bomb::object::FireDown::activate(bomb::game::Game &infos)
{
	return Power::activate(infos);
}
