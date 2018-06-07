//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// PersistentInfo.cpp
//

#include "PersistentInfo.hpp"

bomb::PersistentInfo::PersistentInfo(int plnbr, bool gm, const std::string &f)
	: _playerNbr(plnbr), _generateMap(gm), _fileMap(f)
{
}

const std::string &bomb::PersistentInfo::getFileName() const
{
	return _fileMap;
}

int bomb::PersistentInfo::getPlayerNbr() const
{
	return _playerNbr;
}

bool bomb::PersistentInfo::generateMap() const
{
	return _generateMap;
}

void bomb::PersistentInfo::setFileName(const std::string &filNeame)
{
	_fileMap = filNeame;
}

void bomb::PersistentInfo::setPLayerNbr(int playerNbr)
{
	_playerNbr = playerNbr;
}

void bomb::PersistentInfo::setgenerateMap(bool gm)
{
	_generateMap = gm;
}
