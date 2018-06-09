//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// Player.cpp
//

#include "Player.hpp"

bomb::game::Player::Player(bomb::IAssetLoader &loader,
	const std::string &path,
	std::unique_ptr<bomb::IPlayerController> &controller,
	const irr::core::vector3df &pos,
	const irr::core::vector3df &scale,
	const irr::core::vector3df &rotation,
	bomb::PlayerInfo &info) :
	_maxNbBombs(1),
	_nbBombs(1),
	_speed(0.1f),
	_bombRange(1),
	_ghostMode(false),
	_alive(true),
	_AI(false),
	_bombReady(false),
	_controller(std::move(controller)),
	_genericInfos(info)
{
	info.getActionFromKey(irr::KEY_UP);
	_model = loader.createAnimatedObject(path, pos, scale, rotation);
}

void bomb::game::Player::execute(bomb::Map &map)
{
	(void) map;
/*	if (isAI()) {
		_controller->execute({static_cast<irr::s32>(_obj->getPos().X),
				static_cast<irr::s32>(_obj->getPos().Z)});
		auto action = _controller->requestMovement();
		_actionner.sendAction(map, _obj, action);
	}*/
}

bomb::IPlayerController::Actions
bomb::game::Player::getActionFromEvent(const irr::SEvent &event)
{
	return _genericInfos.getActionFromKey(event.KeyInput.Key);
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

bool bomb::game::Player::isGhostBombMode() const
{
	return _ghostBombMode;
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

void bomb::game::Player::setGhostBombMode(bool _ghostBombMode)
{
	Player::_ghostBombMode = _ghostBombMode;
}

void bomb::game::Player::setAlive(bool _alive, IAssetLoader &loader)
{
	loader.deleteObject(std::move(_model));
	Player::_alive = _alive;
}

bool bomb::game::Player::isAI() const
{
	return _genericInfos.isAI();
}

void bomb::game::Player::setAI(bool AI)
{
	_genericInfos.setIsAI(AI);
}

std::unique_ptr<bomb::AnimatedObject> &bomb::game::Player::getModel()
{
	return _model;
}

void bomb::game::Player::setBombReady(bool value)
{
	_bombReady = value;
}

bool bomb::game::Player::isBombReady()
{
	return _bombReady;
}

irr::core::vector3df bomb::game::Player::getExactPos() const
{
	irr::core::vector3di pos(static_cast<irr::s32>(_model->getPos().X),
			static_cast<irr::s32>(_model->getPos().Y),
			static_cast<irr::s32>(_model->getPos().Z));
	return {static_cast<irr::f32>(pos.X),
		static_cast<irr::f32>(pos.Y),
		static_cast<irr::f32>(pos.Z)};
}