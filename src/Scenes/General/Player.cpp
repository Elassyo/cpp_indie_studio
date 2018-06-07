//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// Player.cpp
//

#include <iostream>
#include "Player.hpp"
#include "../../Interface/IPlayerController.hpp"

bomb::game::Player::Player(bomb::IAssetLoader &loader,
	const std::string &path,
	std::unique_ptr<bomb::IPlayerController> &controller,
	const irr::core::vector3df &pos,
	const irr::core::vector3df &scale,
	const irr::core::vector3df &rotation) :
	_moves{{IPlayerController::UNDEFINED, {0, 0, 0}},
	       {IPlayerController::MV_UP, {0, 0, -1}},
	       {IPlayerController::MV_DOWN, {0, 0, 1}},
	       {IPlayerController::MV_RIGHT, {1, 0, 0}},
	       {IPlayerController::MV_LEFT, {-1, 0, 0}}},
	_nbBombs(1),
	_speed(0.1f),
	_bombRange(1),
	_ghostMode(false),
	_alive(true),
	_characterIndex(0),
	_controller(std::move(controller))
{
	_obj = loader.createAnimatedObject(path, pos, scale, rotation);
}

void bomb::game::Player::execute()
{
	/* dans un thread normalement */
	_controller->execute();

	auto e = _controller->requestMovement();

	/* Faire des method pour les collisions mais la flemme la */
	if (e != IPlayerController::PUT_BOMB)
		_obj->move(_moves.at(e));
}

void bomb::game::Player::startController()
{
	_controller->launch();
}

void bomb::game::Player::closeController()
{
	_controller->close();
}

unsigned char bomb::game::Player::getNbBombs() const
{
	return _nbBombs;
}

float bomb::game::Player::getSpeed() const
{
	return _speed;
}

unsigned char bomb::game::Player::getBombRange() const
{
	return _bombRange;
}

bool bomb::game::Player::isGhostMode() const
{
	return _ghostMode;
}

bool bomb::game::Player::isAlive() const
{
	return _alive;
}

unsigned char bomb::game::Player::getCharacterIndex() const
{
	return _characterIndex;
}

void bomb::game::Player::setNbBombs(unsigned char _nbBombs)
{
	Player::_nbBombs = _nbBombs;
}

void bomb::game::Player::setSpeed(float _speed)
{
	Player::_speed = _speed;
}

void bomb::game::Player::setBombRange(unsigned char _bombRange)
{
	Player::_bombRange = _bombRange;
}

void bomb::game::Player::setGhostMode(bool _ghostMode)
{
	Player::_ghostMode = _ghostMode;
}

void bomb::game::Player::setAlive(bool _alive)
{
	Player::_alive = _alive;
}

void bomb::game::Player::setCharacterIndex(unsigned char _characterIndex)
{
	Player::_characterIndex = _characterIndex;
}
