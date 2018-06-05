//
// EPITECH PROJECT, 2018
// cpp_indie_studio - BombDown.cpp
// File description:
// Created by Gregory EPLE
//

#include "BombDown.hpp"

bomb::object::BombDown::BombDown(bomb::IAssetLoader &loader,
	const irr::core::vector3df &pos) :
	Power(loader, pos, L"models/powers/bombs/bombDown.obj")
{
}

bool bomb::object::BombDown::activate(bomb::game::GameInfo &infos)
{
	return Power::activate(infos);
}
