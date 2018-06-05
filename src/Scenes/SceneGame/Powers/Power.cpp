//
// EPITECH PROJECT, 2018
// cpp_indie_studio - Power.cpp
// File description:
// Created by Gregory EPLE
//

#include "Power.hpp"

bomb::object::Power::Power(bomb::IAssetLoader &loader,
	const irr::core::vector3df &pos, std::string path) :
	_loader(loader), _model(loader.createStaticObject(path, pos))
{
}

bool bomb::object::Power::isActivable(bomb::game::GameInfo &infos)
{
	return false;
}

bool bomb::object::Power::activate(bomb::game::GameInfo &infos)
{
	if (_model)
		_loader.deleteObject(std::move(_model));
	return true;
}