//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// PlaneMesh.cpp
//

#include "PlaneObject.hpp"

bomb::PlaneObject::PlaneObject(
	irr::scene::IMeshSceneNode *animatedNode,
	IAudioPlayer &ap) :
		AObject(animatedNode, ap), _iNode(animatedNode)
{
}

void
bomb::PlaneObject::setTexture(uint32_t layer, irr::video::ITexture *texture)
{
	_iNode->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	_iNode->setMaterialTexture(layer, texture);
}

std::string bomb::PlaneObject::toString()
{
	return "PlaneObject";
}
