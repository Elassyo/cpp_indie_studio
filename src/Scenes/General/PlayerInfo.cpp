//
// EPITECH PROJECT, 2018
// cpp_indie_studios
// File description:
// PlayerInfo.cpp
//

#include "PlayerInfo.hpp"

bomb::PlayerInfo::PlayerInfo() : _isAI(true), _character(game::SHYGUY_WHITE),
	_keys({{irr::KEY_UP, IPlayerController::MV_UP},
		{irr::KEY_DOWN, IPlayerController::MV_DOWN},
		{irr::KEY_LEFT, IPlayerController::MV_LEFT},
		{irr::KEY_RIGHT, IPlayerController::MV_RIGHT},
		{irr::KEY_SPACE, IPlayerController::PUT_BOMB}})
{
}

bool bomb::PlayerInfo::isAI() const
{
	return _isAI;
}

void bomb::PlayerInfo::setIsAI(bool isAI)
{
	_isAI = isAI;
}

bomb::game::Character bomb::PlayerInfo::getCharacter() const
{
	return _character;
}

void bomb::PlayerInfo::setCharacter(bomb::game::Character modelPath)
{
	_character = modelPath;
}

bomb::IPlayerController::Actions
bomb::PlayerInfo::getActionFromKey(irr::EKEY_CODE key) const
{
	if (_keys.find(key) == _keys.end())
		return IPlayerController::UNDEFINED;
	return _keys.at(key);
}
