//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// AIController.cpp
//

#include "AIController.hpp"

bomb::player::AIController::AIController():
	_clock(AI_INTERVAL)
{
}

void bomb::player::AIController::launch()
{
	_clock.reset();
	while (1 /* CONDITION D'ARRET ICI */) {
		if (_clock.isReady()) {
			moveRandom();
			_clock.reset();
		}
	}
}

void bomb::player::AIController::moveRandom()
{
	auto i = rand() % 5;

	_movement.reset();
	switch (i) {
	case 0:
		_movement.top = {true, 1};
		break;
	case 1:
		_movement.bot = {true, 1};
		break;
	case 2:
		_movement.left = {true, 1};
		break;
	case 3:
		_movement.right = {true, 1};
		break;
	default:
		_movement.bomb = true;
	}
}
