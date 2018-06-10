//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// BillboardObject.cpp
//

#include "BillboardObject.hpp"

bomb::BillboardObject::BillboardObject
	(irr::scene::IBillboardSceneNode *billboardSceneNode,
	 bomb::IAudioPlayer &ap) :
	AObject(billboardSceneNode, ap), _inode(billboardSceneNode)
{
}

void bomb::BillboardObject::setTexture
	(uint32_t layer, irr::video::ITexture *texture)
{
	_inode->setMaterialFlag(irr::video::EMF_COLOR_MASK, true);
	_inode->setMaterialType(irr::video::EMT_TRANSPARENT_ADD_COLOR);
	_inode->setMaterialTexture(layer, texture);
}

irr::core::dimension2df bomb::BillboardObject::getSize() const
{
	return _inode->getSize();
}

void bomb::BillboardObject::setSize(const irr::core::dimension2df &scale)
{
	_inode->setSize(scale);
}

std::string bomb::BillboardObject::toString()
{
	return "BillboardObject";
}
