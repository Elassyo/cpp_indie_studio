//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// MapBlockBreakable.cpp
//

#include "MapBlockBreakable.hpp"

bomb::MapBlockBreakable::MapBlockBreakable(
	bomb::IAssetLoader &loader,
	const irr::core::vector3df &pos,
	const irr::core::vector3df &size,
	const irr::core::vector3df &rotation,
	const irr::core::vector3di &mapPos):
	AMapBlock(loader, pos, size, rotation, mapPos, "assets/models/blocks/brick.obj", 1)
{
}

bool bomb::MapBlockBreakable::explode(size_t dammage)
{
	_hp -= 1;
	return dammage <= 0;
}
