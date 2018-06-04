//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// StaticObject.cpp
//

#include "StaticObject.hpp"
#include "Exception/Exception.hpp"

bomb::StaticObject::StaticObject(irr::scene::IMeshSceneNode *inode):
	AObject(inode)
{
	if (!inode)
		throw Exception("AnimatedObject", "staticMashNode cannot be"
						  " created");
}

void bomb::StaticObject::setTexture(uint32_t layer,
				irr::video::ITexture *texture)
{
	_inode->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	_inode->setMaterialTexture(layer, texture);
}

std::string bomb::StaticObject::toString()
{
	return "";
}
