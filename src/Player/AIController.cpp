//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// AIController.cpp
//

#include "AIController.hpp"

bomb::ai::AIController::AIController()
{
}

void bomb::ai::AIController::executeAI(
	bomb::PlayerActionner &actionner,
	std::array<bomb::game::Player, 4> &players,
	bomb::BomberMap &map, int index)
{
	if (rand() % 10000 < 5)
		actionner.sendAction(map, players[(std::size_t)index],
			IPlayerController::PUT_BOMB);
}
