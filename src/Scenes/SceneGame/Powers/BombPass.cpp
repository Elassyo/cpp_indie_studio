//
// EPITECH PROJECT, 2018
// cpp_indie_studio - BombPass.cpp
// File description:
// Created by Gregory EPLE
//

#include "BombPass.hpp"

bomb::object::BombPass::BombPass(bomb::IAssetLoader &loader,
				 const irr::core::vector3df &pos) :
	Power(loader, pos, "assets/models/powers/bombPass/bombPass.obj")
{
}

bool bomb::object::BombPass::activate(
	__attribute__((unused))bomb::game::GameInfo &infos)
{
	if (_model)
		_loader.deleteObject(std::move(_model));
	return true;
}