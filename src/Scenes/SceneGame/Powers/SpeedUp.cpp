//
// EPITECH PROJECT, 2018
// cpp_indie_studio - SpeedUp.cpp
// File description:
// Created by Gregory EPLE
//

#include "SpeedUp.hpp"

bomb::object::SpeedUp::SpeedUp(bomb::IAssetLoader &loader,
	const irr::core::vector3df &pos) :
	Power(loader, pos, "models/powers/speeds/speedUp.obj")
{
}

bool bomb::object::SpeedUp::activate(bomb::game::Game &infos)
{
	return Power::activate(infos);
}
