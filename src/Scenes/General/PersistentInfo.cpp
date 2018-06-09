//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// PersistentInfo.cpp
//

#include "PersistentInfo.hpp"

bomb::PersistentInfo::PersistentInfo(int plnbr, bool gm, const std::string &f)
	: _mapSize(15), _playerNbr(plnbr), _generateMap(gm), _fileMap(f)
{
	_playerInfos[1].setKeys(
		{{irr::KEY_KEY_Z, IPlayerController::MV_UP},
		 {irr::KEY_KEY_S, IPlayerController::MV_DOWN},
		 {irr::KEY_KEY_Q, IPlayerController::MV_LEFT},
		 {irr::KEY_KEY_D, IPlayerController::MV_RIGHT},
		 {irr::KEY_KEY_E, IPlayerController::PUT_BOMB}});
	_playerInfos[2].setKeys(
		{{irr::KEY_KEY_O, IPlayerController::MV_UP},
		 {irr::KEY_KEY_L, IPlayerController::MV_DOWN},
		 {irr::KEY_KEY_K, IPlayerController::MV_LEFT},
		 {irr::KEY_KEY_M, IPlayerController::MV_RIGHT},
		 {irr::KEY_KEY_P, IPlayerController::PUT_BOMB}});
	_playerInfos[3].setKeys(
		{{irr::KEY_KEY_T, IPlayerController::MV_UP},
		 {irr::KEY_KEY_G, IPlayerController::MV_DOWN},
		 {irr::KEY_KEY_F, IPlayerController::MV_LEFT},
		 {irr::KEY_KEY_H, IPlayerController::MV_RIGHT},
		 {irr::KEY_KEY_Y, IPlayerController::PUT_BOMB}});
}

const std::string &bomb::PersistentInfo::getFileName() const
{
	return _fileMap;
}

int bomb::PersistentInfo::getPlayerNbr() const
{
	return _playerNbr;
}

std::array<bomb::PlayerInfo, 4> bomb::PersistentInfo::getPlayerInfos() const
{
	return _playerInfos;
}

bomb::PlayerInfo bomb::PersistentInfo::getPlayerInfos(
	int idx) const
{
	return _playerInfos[idx];
}

bool bomb::PersistentInfo::generateMap() const
{
	return _generateMap;
}

void bomb::PersistentInfo::setFileName(const std::string &filNeame)
{
	_fileMap = filNeame;
}

void bomb::PersistentInfo::setPlayerNbr(int playerNbr)
{
	_playerNbr = playerNbr;
}

void bomb::PersistentInfo::setgenerateMap(bool gm)
{
	_generateMap = gm;
}

void bomb::PersistentInfo::setPlayerInfos(
	std::array<bomb::PlayerInfo, 4> playerInfos)
{
	_playerInfos = playerInfos;
}

void bomb::PersistentInfo::setPlayerInfos(int idx,
					  bomb::PlayerInfo playerinfo)
{
	_playerInfos[idx] = playerinfo;
}

int bomb::PersistentInfo::getMapSize() const
{
	return _mapSize;
}

void bomb::PersistentInfo::setMapSize(int mapSize)
{
	_mapSize = mapSize;
}
