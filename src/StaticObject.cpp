//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// StaticObject.cpp
//

#include "Exception/Exception.hpp"
#include "StaticObject.hpp"

bomb::StaticObject::StaticObject(irr::scene::IMeshSceneNode *node,
				 IAudioPlayer &ap):
	AObject(node, ap), _node(node)
{
	if (!node)
		throw Exception("StaticObject",
			"staticMeshNode cannot be created");
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
