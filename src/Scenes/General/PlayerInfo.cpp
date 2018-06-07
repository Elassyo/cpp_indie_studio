//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// PlayerInfo.cpp
//

#include <iostream>
#include "PlayerInfo.hpp"
#include "../../Interface/IPlayerController.hpp"

bomb::game::PlayerInfo::PlayerInfo(bomb::IAssetLoader &loader,
	const std::string &path,
	std::unique_ptr<bomb::IPlayerController> &controller,
	const irr::core::vector3df &pos,
	const irr::core::vector3df &scale,
	const irr::core::vector3df &rotation,
	const irr::core::vector3di &mapPos):
	_nbBombs(1),
	_speed(10),
	_bombRange(1),
	_ghostMode(false),
	_alive(true),
	_characterIndex(0),
	_controller(std::move(controller))
{
	_obj = loader.createAnimatedObject(path, pos, scale, rotation);
}

void bomb::game::PlayerInfo::execute()
{
	/* dans un thread normalement */
	_controller->execute();

	auto &e = _controller->requestMovement();

	/* Faire des method pour les collisions mais la flemme la */
	if (e.top.first) {
		_obj->move({e.top.second, 0, 0});
	}
	if (e.bot.first) {
		_obj->move({-e.bot.second, 0, 0});
	}
	if (e.left.first) {
		_obj->move({0, 0, e.left.second});
	}
	if (e.right.first) {
		_obj->move({0, 0, -e.right.second});
	}
}

void bomb::game::PlayerInfo::startController()
{
	_controller->launch();
}

void bomb::game::PlayerInfo::closeController()
{
	_controller->close();
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
