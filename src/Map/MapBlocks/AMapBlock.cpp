//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// AMapBlock.cpp
//

#include <src/Interface/IAssetLoader.hpp>
#include "AMapBlock.hpp"

bomb::AMapBlock::AMapBlock(IAssetLoader &loader,
	const irr::core::vector3df &pos,
	const irr::core::vector3df &size,
	const irr::core::vector3df &rotation,
	const irr::core::vector3di &mapPos,
	const std::string &path,
	size_t hp) :
	_mapPos(mapPos), _hp(hp)
{
	_block = loader.createStaticObject(path, pos, size, rotation);
}

const irr::core::vector3di &bomb::AMapBlock::getMapPos() const
{
	return _mapPos;
}

size_t bomb::AMapBlock::getHp() const
{
	return _hp;
}
