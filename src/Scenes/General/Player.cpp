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
	_actionner(true),
	_nbBombs(1),
	_speed(0.1f),
	_bombRange(1),
	_ghostMode(false),
	_alive(true),
	_AI(false),
	_controller(std::move(controller)),
	_keys({{irr::KEY_UP, {IPlayerController::MV_UP, L"Up"}},
		{irr::KEY_DOWN, {IPlayerController::MV_DOWN, L"Down"}},
		{irr::KEY_LEFT, {IPlayerController::MV_LEFT, L"Left"}},
		{irr::KEY_RIGHT, {IPlayerController::MV_RIGHT, L"Right"}}})
{
	_obj = loader.createAnimatedObject(path, pos, scale, rotation);
}

void bomb::game::Player::execute(bomb::Map &map)
{
	if (isAI()) {
		_controller->execute({static_cast<irr::s32>(_obj->getPos().X),
				static_cast<irr::s32>(_obj->getPos().Z)});
		auto action = _controller->requestMovement();
		_actionner.sendAction(map, _obj, action);
	}
	_actionner.actionnate(map, _obj);
}

bool bomb::game::Player::handleEvent(bomb::Map &map, const irr::SEvent &event)
{
	if (_keys.find(event.KeyInput.Key) == _keys.end())
		return true;
	if (event.KeyInput.PressedDown)
		_actionner.sendAction(map, _obj,
			_keys.at(event.KeyInput.Key).first);
	else
		_actionner.removeAction(_keys.at(event.KeyInput.Key).first);
	return true;
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

bool bomb::game::Player::isAI() const
{
	return _AI;
}

void bomb::game::Player::setAI(bool AI)
{
	Player::_AI = AI;
}
