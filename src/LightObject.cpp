//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// LightObject.cpp
//

#include "Exception/Exception.hpp"
#include "LightObject.hpp"

bomb::LightObject::LightObject(irr::scene::ILightSceneNode *node,
			       IAudioPlayer &ap):
	AObject(node, ap), _node(node)
{
	if (!node)
		throw Exception("LightObject",
				"lightMeshNode cannot be created");
}

void bomb::LightObject::setTexture(uint32_t layer,
				   irr::video::ITexture *texture)
{
	_node->setMaterialTexture(layer, texture);
}

std::string bomb::LightObject::toString()
{
	return "LightObject";
}
