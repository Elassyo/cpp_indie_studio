//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// AIController.cpp
//

#include "AIController.hpp"

bomb::ai::AIController::AIController() :
	_moves{{IPlayerController::UNDEFINED, {0, 0, 0}},
	       {IPlayerController::MV_UP, {0, 0, -1}},
	       {IPlayerController::MV_DOWN, {0, 0, 1}},
	       {IPlayerController::MV_RIGHT, {-1, 0, 0}},
	       {IPlayerController::MV_LEFT, {1, 0, 0}}}
{
}

void bomb::ai::AIController::executeAI(
	bomb::PlayerActionner &actionner,
	std::array<bomb::game::Player, 4> &players,
	bomb::BomberMap &map, int index)
{
	auto pos = players[index].getExactPos();
	if (pos.Z == 0 && pos.X == 0 && pos.Y == 0)
		return;
	if (map.getBombRanges()[players[index].getExactPos()] == Map::BOMB)
		executeDefensiveAI(actionner, players, map, index);
	else
		executeOffensiveAI(actionner, players, map, index);
	if (rand() % 10000 < 5)
		actionner.sendAction(map, players[index],
			IPlayerController::PUT_BOMB);
}

void bomb::ai::AIController::executeDefensiveAI(
	bomb::PlayerActionner &actionner,
	std::array<bomb::game::Player, 4> &players,
	bomb::BomberMap &map, int index)

{
	Map safeMap(map.getSize());
	safeMap.addWalls();
}

void bomb::ai::AIController::executeOffensiveAI(
	bomb::PlayerActionner &actionner,
	std::array<bomb::game::Player, 4> &players,
	bomb::BomberMap &map, int index)
{
	std::array<IPlayerController::Actions, 4> moves =
		{IPlayerController::MV_DOWN,
		IPlayerController::MV_LEFT,
		IPlayerController::MV_RIGHT,
		IPlayerController::MV_UP};
	auto move = moves[rand() % 4];
	unsigned int closestP = getClosestEnenemy(players, index);
	auto hisPos = players[closestP].getExactPos();
	auto myPos = players[index].getExactPos();
	auto dir = vecToDir(hisPos - myPos);
	actionner.sendAction(map, players[index], dir);
}

unsigned int bomb::ai::AIController::getClosestEnenemy(
	std::array<bomb::game::Player, 4> &array, int index)
{
	return 0;
}

bomb::IPlayerController::Actions
bomb::ai::AIController::vecToDir(irr::core::vector3d<irr::f32> dir)
{
	dir.normalize();
	if (std::abs(dir.X) > std::abs(dir.Z))
		return dir.X > 0 ? IPlayerController::MV_LEFT :
		       IPlayerController::MV_RIGHT;
	return dir.Z > 0 ? IPlayerController::MV_DOWN :
		IPlayerController::MV_UP;
}
