//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// MapBlockUnbreakable.cpp
//

#include "MapBlockUnbreakable.hpp"

bomb::MapBlockUnbreakable::MapBlockUnbreakable(
	bomb::IAssetManager &loader,
	const irr::core::vector3df &pos,
	const irr::core::vector3df &scale,
	const irr::core::vector3df &rotation,
	const irr::core::vector2di &mapPos):
	AMapBlock(loader, pos, scale, rotation, mapPos,
		"models/blocks/solid.obj", 0)
{
}

bomb::MapBlockUnbreakable::MapBlockUnbreakable():
	AMapBlock()
{
}

std::unique_ptr<bomb::AMapBlock> bomb::MapBlockUnbreakable::clone(
	bomb::IAssetManager &loader,
	const irr::core::vector3df &pos,
	const irr::core::vector3df &scale,
	const irr::core::vector3df &rotation,
	const irr::core::vector2di &mapPos) const
{
	return std::make_unique<MapBlockUnbreakable>
		(loader, pos, scale, rotation, mapPos);
}

bool bomb::MapBlockUnbreakable::explode(size_t damage, IAssetManager &loader)
{
	(void) damage;
	(void) loader;
	return false;
}

std::string bomb::MapBlockUnbreakable::toString()
{
	return "MapBlockUnbreakable";
}
