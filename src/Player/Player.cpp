//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// Player.cpp
//

#include "Player.hpp"
#include "../Interface/IAssetLoader.hpp"

bomb::Player::Player(IAssetLoader &loader, const std::string &path,
	const irr::core::vector3df &pos,
	const irr::core::vector3df &scale,
	const irr::core::vector3df &rotation,
	const irr::core::vector3di &mapPos):
	_mapPos(mapPos)
{
	_obj = loader.createAnimatedObject(path, pos, scale, rotation);
}
