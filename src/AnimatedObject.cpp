//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// AnimatedObject.cpp
//

#include "AnimatedObject.hpp"

bomb::AnimatedObject::AnimatedObject(irr::scene::IAnimatedMeshSceneNode *inode):
		_inode(inode)
{

}

irr::core::vector3df bomb::AnimatedObject::getPos() const
{
	return _inode->getAbsolutePosition();
}

void bomb::AnimatedObject::setPos(const irr::core::vector3df &newPos)
{
	_inode->setPosition(newPos);
}

irr::scene::ISceneNode *bomb::AnimatedObject::getSceneNode() const
{
	return _inode;
}

irr::core::vector3df bomb::AnimatedObject::getRot() const
{
	return _inode->getRotation();
}

void bomb::AnimatedObject::setRot(const irr::core::vector3df &newRot)
{
	_inode->setRotation(newRot);
}

irr::core::vector3df bomb::AnimatedObject::getScale() const
{
	return _inode->getScale();
}

void bomb::AnimatedObject::setScale(const irr::core::vector3df &newScale)
{
	return _inode->setScale(newScale);
}

void bomb::AnimatedObject::setTexture(uint32_t layer, irr::video::ITexture *texture)
{
	_inode->setMaterialTexture(layer, texture);
}

std::string bomb::AnimatedObject::toString()
{
	return "";
}
