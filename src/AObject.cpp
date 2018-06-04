//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// AObject.cpp
//

#include "AObject.hpp"

template<class T>
bomb::AObject<T>::AObject(T *inode) :
	_inode(inode)
{
}

template<class T>
irr::core::vector3df bomb::AObject<T>::getPos() const
{
	return _inode->getAbsolutePosition();
}

template<class T>
void bomb::AObject<T>::setPos(const irr::core::vector3df &newPos)
{
	_inode->setPosition(newPos);
}

template<class T>
irr::core::vector3df bomb::AObject<T>::getRot() const
{
	return _inode->getRotation();
}

template<class T>
void bomb::AObject<T>::setRot(const irr::core::vector3df &newRot)
{
	_inode->setRotation(newRot);
}

template<class T>
irr::core::vector3df bomb::AObject<T>::getScale() const
{
	return _inode->getScale();
}

template<class T>
void bomb::AObject<T>::setScale(const irr::core::vector3df &newScale)
{
	_inode->setScale(newScale);
}

template<class T>
irr::scene::ISceneNode *bomb::AObject<T>::getSceneNode() const
{
	return _inode;
}

template class bomb::AObject<irr::scene::IAnimatedMeshSceneNode>;
template class bomb::AObject<irr::scene::IMeshSceneNode>;
