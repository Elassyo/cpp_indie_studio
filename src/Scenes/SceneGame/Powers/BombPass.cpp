//
// EPITECH PROJECT, 2018
// cpp_indie_studio - BombPass.cpp
// File description:
// Created by Gregory EPLE
//

#include "BombPass.hpp"

bomb::object::BombPass::BombPass(bomb::IAssetManager &loader,
	const irr::core::vector3df &pos) :
	Power(loader, pos, "models/powers/bombPass/bombPass.obj")
{
}

void bomb::object::BombPass::addPower(bomb::game::Player &player)
{
	player.setGhostBombMode(true);
}
