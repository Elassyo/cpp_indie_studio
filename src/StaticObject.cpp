//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// StaticObject.cpp
//

#include "StaticObject.hpp"
#include "Exception/Exception.hpp"

bomb::StaticObject::StaticObject(irr::scene::IMeshSceneNode *node):
	AObject(node), _node(node)
{
	if (!node)
		throw Exception("AnimatedObject", "staticMashNode cannot be"
						  " created");
}

void bomb::StaticObject::setTexture(uint32_t layer,
				irr::video::ITexture *texture)
{
	_node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	_node->setMaterialTexture(layer, texture);
}

std::string bomb::StaticObject::toString()
{
	return "";
}
