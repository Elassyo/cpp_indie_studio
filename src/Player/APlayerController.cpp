//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// APlayerController.cpp
//

#include "APlayerController.hpp"

bomb::APlayerController::APlayerController():
	_end(false), _action(UNDEFINED)
{
}

bomb::IPlayerController::Actions
bomb::APlayerController::requestMovement()
{
	return _action;
}

