//
// EPITECH PROJECT, 2018
// cpp_indie_studio - WallPass.cpp
// File description:
// Created by Gregory EPLE
//

#include "WallPass.hpp"

bomb::object::WallPass::WallPass(bomb::IAssetLoader &loader,
	const irr::core::vector3df &pos) :
	Power(loader, pos, L"models/powers/wallPass/wallPass.obj")
{
}

bool bomb::object::WallPass::activate(bomb::game::GameInfo &infos)
{
	return Power::activate(infos);
}
