//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// AMapBlock.cpp
//

#include "../../Interface/IAssetManager.hpp"
#include "AMapBlock.hpp"

bomb::AMapBlock::AMapBlock(IAssetManager &loader,
	const irr::core::vector3df &pos,
	const irr::core::vector3df &size,
	const irr::core::vector3df &rotation,
	const irr::core::vector2di &mapPos,
	const std::string &path,
	size_t hp) :
	_mapPos(mapPos), _hp(hp)
{
	_block = loader.createStaticObject(path, pos,
		size / BLOCK_OBJ_SIZE, rotation);
}

bomb::AMapBlock::AMapBlock()
{
	_block = nullptr;
}

const irr::core::vector2di &bomb::AMapBlock::getMapPos() const
{
	return _mapPos;
}

size_t bomb::AMapBlock::getHp() const
{
	return _hp;
}

void bomb::AMapBlock::setTextures(irr::video::ITexture *texture)
{
	_block->setTexture(0, texture);
}

void bomb::AMapBlock::destroy(bomb::IAssetManager &manager)
{
	if (_block != nullptr)
		manager.deleteObject(std::move(_block));
}