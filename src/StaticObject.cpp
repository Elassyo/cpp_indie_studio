//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// StaticObject.cpp
//

#include "StaticObject.hpp"
#include "Exception/Exception.hpp"

bomb::StaticObject::StaticObject(irr::scene::IMeshSceneNode *inode):
	_inode(inode)
{
	if (!inode)
		throw Exception("AnimatedObject", "staticMashNode cannot be"
						  " created");
}

irr::core::vector3df bomb::StaticObject::getPos() const
{
	return _inode->getAbsolutePosition();
}

void bomb::StaticObject::setPos(const irr::core::vector3df &newPos)
{
	_inode->setPosition(newPos);
}

irr::scene::ISceneNode *bomb::StaticObject::getSceneNode() const
{
	return _inode;
}

irr::core::vector3df bomb::StaticObject::getRot() const
{
	return _inode->getRotation();
}

void bomb::StaticObject::setRot(const irr::core::vector3df &newRot)
{
	_inode->setRotation(newRot);
}

irr::core::vector3df bomb::StaticObject::getScale() const
{
	return _inode->getScale();
}

void bomb::StaticObject::setScale(const irr::core::vector3df &newScale)
{
	return _inode->setScale(newScale);
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
