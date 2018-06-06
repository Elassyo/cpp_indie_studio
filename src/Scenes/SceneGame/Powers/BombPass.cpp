//
// EPITECH PROJECT, 2018
// cpp_indie_studio - BombPass.cpp
// File description:
// Created by Gregory EPLE
//

#include "BombPass.hpp"

bomb::object::BombPass::BombPass(bomb::IAssetLoader &loader,
	const irr::core::vector3df &pos) :
	Power(loader, pos, "models/powers/bombPass/bombPass.obj")
{
}

bool bomb::object::BombPass::activate(bomb::game::GameInfo &infos)
{
	return Power::activate(infos);
}
