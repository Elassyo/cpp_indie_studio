//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// AnimatedObject.cpp
//

#include "AnimatedObject.hpp"
#include "Exception/Exception.hpp"

bomb::AnimatedObject::AnimatedObject(irr::scene::IAnimatedMeshSceneNode *node):
		AObject(node), _node(node)
{
	if (!node)
		throw Exception("AnimatedObject",
			"animatedMeshNode could not be created");
}

void bomb::AnimatedObject::setTexture(uint32_t layer,
				irr::video::ITexture *texture)
{
	_node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	_node->setMD2Animation(irr::scene::EMAT_STAND);
	_node->setMaterialTexture(layer, texture);
}

std::string bomb::AnimatedObject::toString()
{
	return "";
}

void bomb::AnimatedObject::move(const irr::core::vector3df &v)
{
	_node->setPosition(_node->getPosition() + v);
}

void bomb::AnimatedObject::scale(const irr::core::vector3df &v)
{
	_node->setScale(_node->getScale() + v);

}

void bomb::AnimatedObject::rotate(const irr::core::vector3df &v)
{
	_node->setRotation(_node->getRotation() + v);
}
