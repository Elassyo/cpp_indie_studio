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
	const irr::core::vector3df &scale,
	const irr::core::vector3df &rotation,
	const irr::core::vector3di &mapPos) :
	AMapBlock(loader, pos, scale, rotation, mapPos,
		L"models/blocks/brick.obj", 1)
{
}

bomb::MapBlockBreakable::MapBlockBreakable():
	AMapBlock()
{
}

std::unique_ptr<bomb::AMapBlock> bomb::MapBlockBreakable::clone(
	bomb::IAssetLoader &loader,
	const irr::core::vector3df &pos,
	const irr::core::vector3df &scale,
	const irr::core::vector3df &rotation,
	const irr::core::vector3di &mapPos) const
{
	return std::make_unique<MapBlockBreakable>
		(loader, pos, scale, rotation, mapPos);
}

bool bomb::MapBlockBreakable::explode(size_t damage)
{
	_hp -= 1;
	return damage <= 0;
}
