//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// PlayerActionner.cpp
//

#include <iostream>
#include "PlayerActionner.hpp"
#include "../Scenes/General/Player.hpp"

bomb::PlayerActionner::PlayerActionner() : PlayerActionner(true)
{}

bomb::PlayerActionner::PlayerActionner(bool permanent) :
	_moves{{IPlayerController::UNDEFINED, {0, 0, 0}},
		{IPlayerController::MV_UP, {0, 0, -1}},
		{IPlayerController::MV_DOWN, {0, 0, 1}},
		{IPlayerController::MV_RIGHT, {-1, 0, 0}},
		{IPlayerController::MV_LEFT, {1, 0, 0}}},
	_currentAction(IPlayerController::UNDEFINED),
	_nextAction(IPlayerController::UNDEFINED),
	_target({-1, -1, -1}),
	_speedRatio(0.05f),
	_repeatActionMode(permanent),
	_repeat(permanent),
	_latence(500)
{
}

void bomb::PlayerActionner::addBomb(bomb::BomberMap &map,
	bomb::game::Player &player)
{
	auto tmp = player.getModel()->getPos();
	auto pos = vecfCast(tmp);
	if (player.getNbBombs() >= 1 && map[pos] == BomberMap::EMPTY) {
		player.setNbBombs
			(static_cast<uint8_t>(player.getNbBombs() - 1));
		player.setBombReady(true);
		map[pos] = BomberMap::BOMB;
	}
}

void bomb::PlayerActionner::sendAction(bomb::BomberMap &map,
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

void bomb::PlayerActionner::actionnate(bomb::BomberMap &map,
	bomb::game::Player &player)
{
	if (_currentAction == IPlayerController::UNDEFINED || _target.X == -1) {
		updateAction();
		auto pos = player.getModel()->getPos();
		changeTargetTile(map, vecfCast(pos), player);
	}
	if (_currentAction != IPlayerController::UNDEFINED)
		move(map, player);
}

void bomb::PlayerActionner::move(bomb::BomberMap &map,
	game::Player &player)
{
	_speedRatio = player.getSpeed();
	auto dir = _moves.at(_currentAction) * _speedRatio;
	auto dest = player.getModel()->getPos() + dir;
	if (isTargetReached(dest)) {
		player.getModel()->setPos(veciCast(_target));
		if (!_repeat)
			updateAction();
		changeTargetTile(map, _target, player);
		return;
	}
	player.getModel()->move(dir);
}

void bomb::PlayerActionner::updateAction()
{
	_currentAction = _nextAction;
	_nextAction = IPlayerController::UNDEFINED;
}

void bomb::PlayerActionner::changeTargetTile(bomb::BomberMap &map,
	irr::core::vector3di playerPos,
	game::Player &player)
{
	if (_currentAction != _nextAction &&
		_nextAction != IPlayerController::UNDEFINED)
		updateAction();
	if (_currentAction == IPlayerController::UNDEFINED) {
		_target = {-1, -1, -1};
		return;
	}
	_target = playerPos + vecfCast(_moves[_currentAction]);
	if (map[_target] != BomberMap::EMPTY &&
		(!player.isGhostMode() || map[_target] != BomberMap::BREAKABLE) &&
		(!player.isGhostBombMode() || map[_target] != BomberMap::BOMB)) {
		_target = {-1, -1, -1};
		_currentAction = IPlayerController::UNDEFINED;
	}
	if (_currentAction != IPlayerController::UNDEFINED &&
		_currentAction != IPlayerController::PUT_BOMB) {
		player.getModel()->setRot({0, (float) _currentAction, 0});
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

bomb::IPlayerController::Actions bomb::PlayerActionner::getAction()
{
	return _currentAction;
}

std::unordered_map<bomb::IPlayerController::Actions,
	irr::core::vector3df> &bomb::PlayerActionner::getMoves()
{
	return _moves;
}
