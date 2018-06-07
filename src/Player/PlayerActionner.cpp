//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// PlayerActionner.cpp
//

#include "PlayerActionner.hpp"

bomb::PlayerActionner::PlayerActionner() :
	_moves{{IPlayerController::UNDEFINED, {0, 0, 0}},
		{IPlayerController::MV_UP, {0, 0, -1}},
		{IPlayerController::MV_DOWN, {0, 0, 1}},
		{IPlayerController::MV_RIGHT, {1, 0, 0}},
		{IPlayerController::MV_LEFT, {-1, 0, 0}}},
	_currentAction(IPlayerController::UNDEFINED),
	_nextAction(IPlayerController::UNDEFINED),
	_target({-1, -1, -1})
{
}

void bomb::PlayerActionner::addBomb(bomb::Map &map,
	std::unique_ptr <bomb::AnimatedObject> &player)
{
}

void bomb::PlayerActionner::sendAction(bomb::Map &map,
	std::unique_ptr <bomb::AnimatedObject> &player,
	bomb::IPlayerController::Actions action)
{
	if (action == IPlayerController::PUT_BOMB)
		return addBomb(map, player);
	else if (action != IPlayerController::UNDEFINED)
		_nextAction = action;
}

void bomb::PlayerActionner::actionnate(bomb::Map &map,
	std::unique_ptr <bomb::AnimatedObject> &player)
{
	if (_currentAction == IPlayerController::UNDEFINED)
		changeTargetTile(map, player);
	if (_currentAction == IPlayerController::UNDEFINED)
		return;
	move(map, player);
}

void bomb::PlayerActionner::move(bomb::Map &map,
	std::unique_ptr <bomb::AnimatedObject> &player)
{
	auto dir = _moves.at(_currentAction) * _speedRatio;
	if (isTargetReached(dir)) {
		player->setPos(veciCast(_target));
		return changeTargetTile(map, player);
	}
	player->move(dir);
}

void bomb::PlayerActionner::changeTargetTile(bomb::Map &map,
	std::unique_ptr <bomb::AnimatedObject> &player)
{
	_currentAction = _nextAction;
	_nextAction = IPlayerController::UNDEFINED;
	if (_currentAction == IPlayerController::UNDEFINED)
		return;
	auto playerPos = player->getPos();
	_target = vecfCast(playerPos) + vecfCast(_moves[_currentAction]);
	if (map[_target] != Map::EMPTY) {
		_target = {-1, -1, -1};
		_currentAction = IPlayerController::UNDEFINED;
	}
}

bool bomb::PlayerActionner::isTargetReached
	(irr::core::vector3d<irr::f32> &pos)
{

	return (sqrt(pow((float)_target.X - pos.X, 2)
		+ (float)pow(_target.Y - pos.Y, 2))
		< _speedRatio + 0.1);
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