//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// PlayerActionner.cpp
//

#include "PlayerActionner.hpp"

void bomb::PlayerActionner::actionnate(bomb::Map &map,
				std::unique_ptr <bomb::AnimatedObject> &obj,
				bomb::IPlayerController::Actions action)
{
	(void) map;
	(void) obj;
	(void) action;
}

void bomb::PlayerActionner::setSpeedRatio(float speedRatio)
{
	_speedRatio = speedRatio;
}