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
	if (rand() % 100 < 5)
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
	auto myPos = players[index].getExactPos();
	irr::core::vector2di my2dPos = {static_cast<irr::s32>(myPos.X),
					static_cast<irr::s32>(myPos.Z)};
	auto action = searchSaferBlock(map, safeMap, my2dPos);
	actionner.sendAction(map, players[index], action);
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
	std::array<bomb::game::Player, 4> &players, int index)
{
	auto myPos = players[index].getExactPos();
	float max = 0;
	unsigned int maxIndex = 0;

	for (unsigned int i = 0; i < players.size(); ++i) {
		if (i == index)
			continue;
		auto hisPos = players[index].getExactPos();
		auto diff = myPos.getDistanceFrom(hisPos);
		if (diff > max) {
			max = diff;
			maxIndex = i;
		}
	}
	return maxIndex;
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

std::map<irr::core::vector2di, bomb::IPlayerController::Actions>
        bomb::ai::AIController::searchSaferBlock(
	bomb::BomberMap &map, bomb::Map safeMap,
	std::map<irr::core::vector2di, IPlayerController::Actions> poses,
	IPlayerController::Actions &action)
{
	std::map<irr::core::vector2di, IPlayerController::Actions> vec;
	for (auto tmp : poses) {
		for (auto &tmp2 : _moves) {
			if (map[tmp.second] != Map::EMPTY)
				continue;
			auto pos = tmp.first + irr::core::vector2di(
				static_cast<irr::s32>(tmp2.second.X),
				static_cast<irr::s32>(tmp2.second.Z));
			if (map[pos] == Map::EMPTY) {
				vec[pos] = tmp.second;
				safeMap[pos] = (Map::BlockType) tmp2.first;
				if (map.getBombRanges()[pos] == Map::EMPTY) {
					action = tmp.second;
					return vec;
				}
			}
		}
	}
	return vec;
}

bomb::IPlayerController::Actions bomb::ai::AIController::searchSaferBlock(
	bomb::BomberMap &map, bomb::Map &safeMap, irr::core::vector2di vector2d)
{
	std::map<irr::core::vector2di, bomb::IPlayerController::Actions> dirs
		({{{vector2d.X, vector2d.Y - 1}, IPlayerController::MV_UP},
		 {{vector2d.X, vector2d.Y + 1}, IPlayerController::MV_DOWN},
		 {{vector2d.X - 1, vector2d.Y}, IPlayerController::MV_RIGHT},
		 {{vector2d.X + 1, vector2d.Y}, IPlayerController::MV_LEFT}});

	if (map[vector2d] == Map::UNBREAKABLE)
		return IPlayerController::UNDEFINED;
	IPlayerController::Actions action = IPlayerController::UNDEFINED;
	while (!dirs.empty() && action == IPlayerController::UNDEFINED) {
		dirs = searchSaferBlock(map, safeMap, dirs, action);
	}
	return action;
}
