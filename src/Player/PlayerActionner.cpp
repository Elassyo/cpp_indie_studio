//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// PlayerActionner.cpp
//

#include "PlayerActionner.hpp"

void bomb::PlayerActionner::addBomb(bomb::Map &map,
	std::unique_ptr <bomb::AnimatedObject> &player)
{
}

void bomb::PlayerActionner::move(bomb::Map &map,
	std::unique_ptr <bomb::AnimatedObject> &player,
	bomb::IPlayerController::Actions action)
{
}

void bomb::PlayerActionner::actionnate(bomb::Map &map,
	std::unique_ptr <bomb::AnimatedObject> &player,
	bomb::IPlayerController::Actions action)
{
	if (action == IPlayerController::PUT_BOMB)
		return addBomb(map, player);
	else if (action != IPlayerController::UNDEFINED)
		return move(map, player, action);
}

void bomb::PlayerActionner::setSpeedRatio(float speedRatio)
{
	_speedRatio = speedRatio;
}