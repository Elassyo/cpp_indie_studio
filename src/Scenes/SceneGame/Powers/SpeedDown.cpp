//
// EPITECH PROJECT, 2018
// cpp_indie_studio - SpeedDown.cpp
// File description:
// Created by Gregory EPLE
//

#include "SpeedDown.hpp"

bomb::object::SpeedDown::SpeedDown(bomb::IAssetLoader &loader,
	const irr::core::vector3df &pos) :
	Power(loader, pos, L"models/powers/speeds/speedUp.obj")
{
}

bool bomb::object::SpeedDown::activate(bomb::game::GameInfo &infos)
{
	return Power::activate(infos);
}
