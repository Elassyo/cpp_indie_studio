//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// BillboardObject.cpp
//

#include "BillboardObject.hpp"

bomb::BillboardObject::BillboardObject
	(irr::scene::IBillboardSceneNode *billboardSceneNode, bomb::IAudioPlayer &ap) :
	AObject(billboardSceneNode, ap), _inode(billboardSceneNode)
{
}

void bomb::BillboardObject::setTexture
	(uint32_t layer, irr::video::ITexture *texture)
{
	_inode->setMaterialTexture(layer, texture);
}

std::string bomb::BillboardObject::toString()
{
	return "BillboardObject";
}
