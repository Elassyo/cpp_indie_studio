//
// EPITECH PROJECT, 2018
// cpp_indie_studio - SpeedDown.cpp
// File description:
// Created by Gregory EPLE
//

#include "SpeedDown.hpp"

bomb::object::SpeedDown::SpeedDown(bomb::IAssetLoader &loader,
				   const irr::core::vector3df &pos) :
	Power(loader, pos, "assets/models/powers/speeds/speedUp.obj")
{
}

bool bomb::object::SpeedDown::activate(
	__attribute__((unused))bomb::game::GameInfo &infos)
{
	if (_model)
		_loader.deleteObject(std::move(_model));
	return true;
}