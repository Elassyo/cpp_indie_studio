//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// MapBlockUnbreakable.cpp
//

#include "MapBlockUnbreakable.hpp"

bomb::MapBlockUnbreakable::MapBlockUnbreakable(
	bomb::IAssetLoader &loader,
	const irr::core::vector3df &pos,
	const irr::core::vector3df &scale,
	const irr::core::vector3df &rotation,
	const irr::core::vector3di &mapPos):
	AMapBlock(loader, pos, scale, rotation, mapPos,
		"assets/models/blocks/solid.obj", 0)
{
}

bomb::MapBlockUnbreakable::MapBlockUnbreakable():
	AMapBlock()
{
}

std::unique_ptr<bomb::AMapBlock> bomb::MapBlockUnbreakable::clone(
	bomb::IAssetLoader &loader,
	const irr::core::vector3df &pos,
	const irr::core::vector3df &scale,
	const irr::core::vector3df &rotation,
	const irr::core::vector3di &mapPos) const
{
	return std::make_unique<MapBlockUnbreakable>
		(loader, pos, scale, rotation, mapPos);
}

bool bomb::MapBlockUnbreakable::explode(size_t damage)
{
	return false;
}
