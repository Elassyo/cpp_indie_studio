//
// EPITECH PROJECT, 2018
// cpp_indie_studio - BombDown.cpp
// File description:
// Created by Gregory EPLE
//

#include "BombDown.hpp"

bomb::object::BombDown::BombDown(bomb::IAssetLoader &loader,
				 const irr::core::vector3df &pos) :
	Power(loader, pos, "assets/models/powers/bombs/bombDown.obj")
{
}

bool bomb::object::BombDown::activate(
	__attribute__((unused))bomb::game::GameInfo &infos)
{
	if (_model)
		_loader.deleteObject(std::move(_model));
	return true;
}