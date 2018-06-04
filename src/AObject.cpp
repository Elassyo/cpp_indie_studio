//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// AObject.cpp
//

#include "AObject.hpp"

bomb::AObject::AObject(irr::scene::ISceneNode *inode) :
	_node(inode)
{
}

irr::core::vector3df bomb::AObject::getPos() const
{
	return _node->getAbsolutePosition();
}

void bomb::AObject::setPos(const irr::core::vector3df &newPos)
{
	_node->setPosition(newPos);
}

irr::core::vector3df bomb::AObject::getRot() const
{
	return _node->getRotation();
}

void bomb::AObject::setRot(const irr::core::vector3df &newRot)
{
	_node->setRotation(newRot);
}

irr::core::vector3df bomb::AObject::getScale() const
{
	return _node->getScale();
}

void bomb::AObject::setScale(const irr::core::vector3df &newScale)
{
	_node->setScale(newScale);
}

irr::scene::ISceneNode *bomb::AObject::getSceneNode() const
{
	return _node;
}
