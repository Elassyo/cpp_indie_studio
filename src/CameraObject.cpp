//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// CameraObject.cpp
//

#include <cstdint>
#include <irrlicht/ITexture.h>
#include "CameraObject.hpp"

bomb::CameraObject::CameraObject(irr::scene::ICameraSceneNode *inode,
AudioManager &al) :
	AObject(inode, al), _inode(inode), _audioListener(al)
{

}

void bomb::CameraObject::setTexture
	(uint32_t layer, irr::video::ITexture *texture)
{
	(void) layer;
	(void) texture;
}

std::string bomb::CameraObject::toString()
{
	return "CameraObject";
}

void bomb::CameraObject::setPos(const irr::core::vector3df &v)
{
	_inode->setPosition(v);
	_audioListener.updateListener(_inode);
}

void bomb::CameraObject::setRot(const irr::core::vector3df &v)
{
	_inode->setRotation(v);
	_audioListener.updateListener(_inode);
}
