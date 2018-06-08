//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// PlayerActionner.cpp
//

#include <iostream>
#include "PlayerActionner.hpp"
#include "../Scenes/General/Player.hpp"

bomb::PlayerActionner::PlayerActionner(bool permanent) :
	_moves{{IPlayerController::UNDEFINED, {0, 0, 0}},
		{IPlayerController::MV_UP, {0, 0, -1}},
		{IPlayerController::MV_DOWN, {0, 0, 1}},
		{IPlayerController::MV_RIGHT, {-1, 0, 0}},
		{IPlayerController::MV_LEFT, {1, 0, 0}}},
	_currentAction(IPlayerController::UNDEFINED),
	_nextAction(IPlayerController::UNDEFINED),
	_target({-1, -1, -1}),
	_speedRatio(0.05),
	_repeatActionMode(permanent),
	_repeat(permanent),
	_latence(500)
{
}

void bomb::PlayerActionner::addBomb(bomb::Map &map,
	bomb::game::Player &player)
{
	auto tmp = player.getModel()->getPos();
	auto pos = vecfCast(tmp);
	if (player.getNbBombs() >= 1 && map[pos] == Map::EMPTY) {
		player.setNbBombs
			(static_cast<uint8_t>(player.getNbBombs() - 1));
		player.setBombReady(true);
	}
}

void bomb::PlayerActionner::sendAction(bomb::Map &map,
	bomb::game::Player &player,
	bomb::IPlayerController::Actions action)
{
	if (action == IPlayerController::PUT_BOMB)
		return addBomb(map, player);
	else if (action != IPlayerController::UNDEFINED) {
		_repeat = _repeatActionMode;
		if (_latence.isReady() || action != _currentAction) {
			_latence.reset();
			_nextAction = action;
		}
	}
}

void bomb::PlayerActionner::actionnate(bomb::Map &map,
	bomb::game::Player &player)
{
	if (_currentAction == IPlayerController::UNDEFINED || _target.X == -1) {
		updateAction();
		auto pos = player.getModel()->getPos();
		changeTargetTile(map, vecfCast(pos), player.getModel());
	}
	if (_currentAction != IPlayerController::UNDEFINED)
		move(map, player.getModel());
}

void bomb::PlayerActionner::move(bomb::Map &map,
	std::unique_ptr <bomb::AnimatedObject> &player)
{
	auto dir = _moves.at(_currentAction) * _speedRatio;
	auto dest = player->getPos() + dir;
	if (isTargetReached(dest)) {
		player->setPos(veciCast(_target));
		if (!_repeat)
			updateAction();
		changeTargetTile(map, _target, player);
		return;
	}
	player->move(dir);
}

void bomb::PlayerActionner::updateAction()
{
	_currentAction = _nextAction;
	_nextAction = IPlayerController::UNDEFINED;
}

void bomb::PlayerActionner::changeTargetTile(bomb::Map &map,
	irr::core::vector3di playerPos,
	std::unique_ptr <bomb::AnimatedObject> &player)
{
	auto saveAct = _currentAction;
	if (_currentAction != _nextAction &&
		_nextAction != IPlayerController::UNDEFINED)
		updateAction();
	if (_currentAction == IPlayerController::UNDEFINED) {
		_target = {-1, -1, -1};
		return;
	}
	_target = playerPos + vecfCast(_moves[_currentAction]);
	if (map[_target] != Map::EMPTY) {
		_target = {-1, -1, -1};
		_currentAction = IPlayerController::UNDEFINED;
	}
	if (_currentAction != IPlayerController::UNDEFINED &&
		_currentAction != IPlayerController::PUT_BOMB) {
		player->setRot({0, (float) _currentAction, 0});
	}
}

bool bomb::PlayerActionner::isTargetReached
	(irr::core::vector3d<irr::f32> &pos)
{

	return (sqrt(pow((float)_target.X - (float)pos.X, 2)
		+ (pow((float)_target.Z - (float)pos.Z, 2)))
		<= _speedRatio);
}

void bomb::PlayerActionner::setSpeedRatio(float speedRatio)
{
	_speedRatio = speedRatio;
}

irr::core::vector3di bomb::PlayerActionner::vecfCast(irr::core::vector3df &vec)
{
	return {static_cast<irr::s32>(vec.X),
		static_cast<irr::s32>(vec.Y),
		static_cast<irr::s32>(vec.Z)};
}

irr::core::vector3df bomb::PlayerActionner::veciCast(irr::core::vector3di &vec)
{
	return {static_cast<irr::f32>(vec.X),
		static_cast<irr::f32>(vec.Y),
		static_cast<irr::f32>(vec.Z)};
}

void
bomb::PlayerActionner::removeAction(bomb::IPlayerController::Actions actions)
{
	if (actions == _currentAction) {
		_repeat = false;
		if (_repeatActionMode && _currentAction == _nextAction)
			_nextAction = IPlayerController::UNDEFINED;
	}
}
