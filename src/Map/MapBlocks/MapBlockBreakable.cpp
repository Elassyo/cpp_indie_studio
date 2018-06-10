//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// MapBlockBreakable.cpp
//

#include "MapBlockBreakable.hpp"

bomb::MapBlockBreakable::MapBlockBreakable(
	bomb::IAssetManager &loader,
	const irr::core::vector3df &pos,
	const irr::core::vector3df &scale,
	const irr::core::vector3df &rotation,
	const irr::core::vector2di &mapPos) :
	AMapBlock(loader, pos, scale, rotation, mapPos,
		"models/blocks/brick.obj", 1)
{
}

bomb::MapBlockBreakable::MapBlockBreakable():
	AMapBlock()
{
}

std::unique_ptr<bomb::AMapBlock> bomb::MapBlockBreakable::clone(
	bomb::IAssetManager &loader,
	const irr::core::vector3df &pos,
	const irr::core::vector3df &scale,
	const irr::core::vector3df &rotation,
	const irr::core::vector2di &mapPos) const
{
	return std::make_unique<MapBlockBreakable>
		(loader, pos, scale, rotation, mapPos);
}

bool bomb::MapBlockBreakable::explode(
	size_t damage, bomb::IAssetManager &loader)
{
	_hp -= damage;
	loader.deleteObject(std::move(_block));
	return _hp <= 0;
}

std::string bomb::MapBlockBreakable::toString()
{
	return "MapBlockBreakable";
}
