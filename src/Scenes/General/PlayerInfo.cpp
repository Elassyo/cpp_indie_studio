//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// PlayerInfo.cpp
//

#include "PlayerInfo.hpp"

bomb::game::PlayerInfo::PlayerInfo() :
	_nbBombs(1), _speed(10), _bombRange(1), _ghostMode(false), _alive(true),
	_characterIndex(0)
{
}

unsigned char bomb::game::PlayerInfo::getNbBombs() const
{
	return _nbBombs;
}

unsigned char bomb::game::PlayerInfo::getSpeed() const
{
	return _speed;
}

unsigned char bomb::game::PlayerInfo::getBombRange() const
{
	return _bombRange;
}

bool bomb::game::PlayerInfo::isGhostMode() const
{
	return _ghostMode;
}

bool bomb::game::PlayerInfo::isAlive() const
{
	return _alive;
}

unsigned char bomb::game::PlayerInfo::getCharacterIndex() const
{
	return _characterIndex;
}

void bomb::game::PlayerInfo::setNbBombs(unsigned char _nbBombs)
{
	PlayerInfo::_nbBombs = _nbBombs;
}

void bomb::game::PlayerInfo::setSpeed(unsigned char _speed)
{
	PlayerInfo::_speed = _speed;
}

void bomb::game::PlayerInfo::setBombRange(unsigned char _bombRange)
{
	PlayerInfo::_bombRange = _bombRange;
}

void bomb::game::PlayerInfo::setGhostMode(bool _ghostMode)
{
	PlayerInfo::_ghostMode = _ghostMode;
}

void bomb::game::PlayerInfo::setAlive(bool _alive)
{
	PlayerInfo::_alive = _alive;
}

void bomb::game::PlayerInfo::setCharacterIndex(unsigned char _characterIndex)
{
	PlayerInfo::_characterIndex = _characterIndex;
}
