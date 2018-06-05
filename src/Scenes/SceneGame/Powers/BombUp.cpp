//
// EPITECH PROJECT, 2018
// cpp_indie_studio - BombUp.cpp
// File description:
// Created by Gregory EPLE
//

#include "BombUp.hpp"

bomb::object::BombUp::BombUp(bomb::IAssetLoader &loader,
	const irr::core::vector3df &pos) :
	Power(loader, pos, L"models/powers/bombs/bombUp.obj")
{
}

bool bomb::object::BombUp::activate(bomb::game::GameInfo &infos)
{
	return Power::activate(infos);
}
