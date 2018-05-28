//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// AObject.cpp
//

#include "AObject.hpp"

bomb::AObject::AObject(
	const irr::core::vector3df &pos,
	const irr::core::vector3df &scale,
	const irr::core::vector3df &rotation):
	_pos(pos), _scale(scale), _rotation(rotation)
{
}

const irr::core::vector3df &bomb::AObject::getPos() const
{
	return _pos;
}

irr::core::vector3df &bomb::AObject::getRPos() const
{
	return _pos;
}

void bomb::AObject::setPos(const irr::core::vector3df &pos)
{
	AObject::_pos = pos;
}

const irr::core::vector3df &bomb::AObject::getScale() const
{
	return _scale;
}

irr::core::vector3df &bomb::AObject::getRScale() const
{
	return _scale;
}

void bomb::AObject::setScale(const irr::core::vector3df &scale)
{
	AObject::_scale = scale;
}

const irr::core::vector3df &bomb::AObject::getRotation() const
{
	return _rotation;
}

irr::core::vector3df &bomb::AObject::getRRotation() const
{
	return _rotation;
}

void bomb::AObject::setRotation(const irr::core::vector3df &rotation)
{
	AObject::_rotation = rotation;
}
