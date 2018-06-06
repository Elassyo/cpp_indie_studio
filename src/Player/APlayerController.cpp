//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// APlayerController.cpp
//

#include "APlayerController.hpp"

const bomb::MovementAnalyser &bomb::APlayerController::requestMovement() const
{
	return _movement;
}
