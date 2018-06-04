//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// AnimatedObject.cpp
//

#include "AnimatedObject.hpp"
#include "Exception/Exception.hpp"

bomb::AnimatedObject::AnimatedObject(irr::scene::IAnimatedMeshSceneNode *inode):
		AObject(inode)
{
	if (!inode)
		throw Exception("AnimatedObject", "animatedMashNode cannot be"
				    " created");
}

void bomb::AnimatedObject::setTexture(uint32_t layer,
				irr::video::ITexture *texture)
{
	_inode->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	_inode->setMD2Animation(irr::scene::EMAT_STAND);
	_inode->setMaterialTexture(layer, texture);
}

std::string bomb::AnimatedObject::toString()
{
	return "";
}
