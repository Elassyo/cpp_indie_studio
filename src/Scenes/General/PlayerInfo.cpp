//
// EPITECH PROJECT, 2018
// cpp_indie_studios
// File description:
// PlayerInfo.cpp
//

#include "PlayerInfo.hpp"

bomb::PlayerInfo::PlayerInfo() : _isAI(true), _modelPath(nullptr)
{}

bool bomb::PlayerInfo::isAI() const
{
	return _isAI;
}

void bomb::PlayerInfo::setIsAI(bool isAI)
{
	_isAI = isAI;
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
	_keys = keys;
}

wchar_t *bomb::PlayerInfo::getModelPath() const
{
	return _modelPath;
}

void bomb::PlayerInfo::setModelPath(wchar_t *modelPath)
{
	PlayerInfo::_modelPath = modelPath;
}
