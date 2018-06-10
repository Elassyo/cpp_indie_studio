//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// CharacterInfo.cpp
//

#include "CharacterInfo.hpp"
#include <utility>

bomb::game::CharacterInfo::CharacterInfo(const wchar_t *name,
					std::string modelPath,
					std::string iconPath,
					std::string hitSfxPath) :
	_name(name), _modelPath(std::move(modelPath)),
	_iconPath(std::move(iconPath)), _hitSfxPath(hitSfxPath),
	_texture(nullptr)
{}

const wchar_t *bomb::game::CharacterInfo::getName()
{
	return _name;
}

std::string &bomb::game::CharacterInfo::getModelPath()
{
	return _modelPath;
}

std::string &bomb::game::CharacterInfo::getIconPath()
{
	return _iconPath;
}

std::string &bomb::game::CharacterInfo::getHitSfxPath()
{
	return _hitSfxPath;
}

irr::video::ITexture *bomb::game::CharacterInfo::getTexture() const
{
	return _texture;
}

void bomb::game::CharacterInfo::setTexture(irr::video::ITexture *texture)
{
	CharacterInfo::_texture = texture;
}
