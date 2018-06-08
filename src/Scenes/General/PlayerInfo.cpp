//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// PlayerInfo.cpp
//

#include "PlayerInfo.hpp"

bool bomb::PlayerInfo::isIsAI() const
{
	return _isAI;
}

void bomb::PlayerInfo::setIsAI(bool isAI)
{
	PlayerInfo::_isAI = isAI;
}

const std::unordered_map <irr::EKEY_CODE,
	std::pair<bomb::IPlayerController::Actions, wchar_t *>>
	&bomb::PlayerInfo::getKeys() const
{
	return _keys;
}

void bomb::PlayerInfo::setKeys(
	const std::unordered_map<irr::EKEY_CODE,
	std::pair<bomb::IPlayerController::Actions,wchar_t *>> &keys) {
	PlayerInfo::_keys = keys;
}

wchar_t *bomb::PlayerInfo::getModelPath() const
{
	return _modelPath;
}

void bomb::PlayerInfo::setModelPath(wchar_t *modelPath)
{
	PlayerInfo::_modelPath = modelPath;
}
