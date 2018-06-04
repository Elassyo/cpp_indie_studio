//
// EPITECH PROJECT, 2018
// cpp_indie_studio - FireUp.cpp
// File description:
// Created by Gregory EPLE
//

#include "FireUp.hpp"

bomb::object::FireUp::FireUp(bomb::IAssetLoader &loader,
			     const irr::core::vector3df &pos) :
	Power(loader, pos, "assets/models/powers/fires/fireUp.obj")
{
}

bool bomb::object::FireUp::activate(
	__attribute__((unused))bomb::game::GameInfo &infos)
{
	if (_model)
		_loader.deleteObject(std::move(_model));
	return true;
}