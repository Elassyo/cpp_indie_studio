//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// PlaneMesh.cpp
//

#include "PlaneObject.hpp"

bomb::PlaneObject::PlaneObject(
	irr::scene::IAnimatedMeshSceneNode *animatedNode,
	IAudioPlayer &ap) :
		AObject(animatedNode, ap), _animatedNode(animatedNode)
{
}

void
bomb::PlaneObject::setTexture(uint32_t layer, irr::video::ITexture *texture)
{
	_animatedNode->setMaterialTexture(layer, texture);
}

std::string bomb::PlaneObject::toString()
{
	return "PlaneObject";
}
