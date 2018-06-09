//
// EPITECH PROJECT, 2018
// cpp_indie_studio - WallPass.cpp
// File description:
// Created by Gregory EPLE
//

#include "WallPass.hpp"

bomb::object::WallPass::WallPass(bomb::IAssetManager &loader,
	const irr::core::vector3df &pos) :
	Power(loader, pos, "models/powers/wallPass/wallPass.obj")
{
}

void bomb::object::WallPass::addPower(bomb::game::Player &player)
{
	player.setGhostMode(true);
}
