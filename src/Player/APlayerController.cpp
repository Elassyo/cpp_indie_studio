//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// APlayerController.cpp
//

#include "APlayerController.hpp"

bomb::APlayerController::APlayerController():
	_end(false)
{
}

const bomb::MovementAnalyser &bomb::APlayerController::requestMovement()
{
	return _movement;
}

void bomb::APlayerController::close()
{
	_end = true;
}
