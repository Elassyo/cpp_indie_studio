//
// EPITECH PROJECT, 2018
// cpp_indie_studio - FireFull.cpp
// File description:
// Created by Gregory EPLE
//

#include "FireFull.hpp"

bomb::object::FireFull::FireFull(bomb::IAssetLoader &loader,
				 const irr::core::vector3df &pos) :
	Power(loader, pos, "assets/models/powers/fires/fireFull.obj")
{
}

bool bomb::object::FireFull::activate(
	__attribute__((unused))bomb::game::GameInfo &infos)
{
	if (_model)
		_loader.deleteObject(std::move(_model));
	return true;
}