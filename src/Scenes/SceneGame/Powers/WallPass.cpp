//
// EPITECH PROJECT, 2018
// cpp_indie_studio - WallPass.cpp
// File description:
// Created by Gregory EPLE
//

#include "WallPass.hpp"

bomb::object::WallPass::WallPass(bomb::IAssetLoader &loader,
	const irr::core::vector3df &pos) :
	Power(loader, pos, "models/powers/wallPass/wallPass.obj")
{
}

bool bomb::object::WallPass::activate(bomb::Map &map, bomb::game::Player &player)
{
	return Power::activate(map, player);
}
