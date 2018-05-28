//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// ATransformableObject.cpp
//

#include "ATransformableObject.hpp"

bomb::ATransformableObject::ATransformableObject(
	const irr::core::vector3df &pos,
	const irr::core::vector3df &scale,
	const irr::core::vector3df &rotation):
	AObject(pos, scale, rotation)
{
}

void bomb::ATransformableObject::move(const irr::core::vector3df &df)
{
	_pos += df;
}

void bomb::ATransformableObject::rotate(const irr::core::vector3df &df)
{
	_rotation += df;
}

void bomb::ATransformableObject::scale(const irr::core::vector3df &df)
{
	_scale += df;
}
