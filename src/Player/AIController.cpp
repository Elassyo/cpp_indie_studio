//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// AIController.cpp
//

#include "AIController.hpp"

bomb::player::AIController::AIController():
	APlayerController(), _clock(AI_INTERVAL)
{
}

void bomb::player::AIController::launch()
{
	_clock.reset();
	while (!_end) {
		if (_clock.isReady()) {
			execute();
			_clock.reset();
		}
	}
}

void bomb::player::AIController::execute()
{
	moveRandom();
}

void bomb::player::AIController::moveRandom()
{
	auto acts = std::vector({MV_UP, MV_DOWN, MV_LEFT, MV_RIGHT, PUT_BOMB});
	_action = acts.at(rand() % acts.size());
}
