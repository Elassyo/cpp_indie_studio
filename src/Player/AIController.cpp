//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// AIController.cpp
//

#include <algorithm>
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
	if ((pos.Z == 0 && pos.X == 0 && pos.Y == 0) ||
		actionner.getAction() != IPlayerController::UNDEFINED)
		return;
	if (map[pos] == Map::BOMB && map.getBombRanges()[pos] != Map::BOMB)
		return;
	if (map.getBombRanges()[pos] == Map::BOMB)
		executeDefensiveAI(actionner, players, map, index);
	else
		executeOffensiveAI(actionner, players, map, index);
}

void bomb::ai::AIController::executerRandomAI(
	bomb::PlayerActionner &actionner,
	std::array<bomb::game::Player, 4> &players,
	bomb::BomberMap &map, int index)
{
	std::array<IPlayerController::Actions, 4> moves =
		{IPlayerController::MV_DOWN,
		IPlayerController::MV_LEFT,
		IPlayerController::MV_UP,
		IPlayerController::MV_RIGHT};
	std::random_shuffle(moves.begin(), moves.end());
	for (unsigned int i = 0; i < 4; ++i) {
		auto &move = moves[i];
		auto pos = players[index].getExactPos() + _moves[move];
		if (map.getBombRanges()[pos] == Map::EMPTY &&
		    map[pos] == Map::EMPTY)
			return actionner.sendAction(map, players[index], move);
	}
}


void bomb::ai::AIController::executeDefensiveAI(
	bomb::PlayerActionner &actionner,
	std::array<bomb::game::Player, 4> &players,
	bomb::BomberMap &map, int index)

{
	Map safeMap(map.getSize());
	safeMap.addWalls();
	auto myPos = players[index].getExactPos();
	if (map.getBombRanges()[myPos] == Map::EMPTY &&
	    map[myPos] == Map::EMPTY)
		return;
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
	if (isValidBombPlace(players, map, index))
		return actionner.sendAction(
			map, players[index], IPlayerController::PUT_BOMB);
	for (auto &dir : getEnenemyDirections(players, index)) {
		if (dir.second == IPlayerController::UNDEFINED)
			continue;
		auto nextCell = getNextCell(players, index, dir.second);
		if (dir.second == IPlayerController::PUT_BOMB ||
			(map.getBombRanges()[nextCell] == Map::EMPTY &&
			map[nextCell] == Map::EMPTY))
			return actionner.sendAction
				(map, players[index], dir.second);
	}
	executerRandomAI(actionner, players, map, index);
}

irr::core::vector3d<irr::f32> bomb::ai::AIController::getNextCell(
	irr::core::vector3df &pos, IPlayerController::Actions &action)
{
	return pos + _moves[action];
}

irr::core::vector3d<irr::f32> bomb::ai::AIController::getNextCell(
	std::array<bomb::game::Player, 4> &players, int index,
	IPlayerController::Actions &action)
{
	if (index < 0 || index >= 4)
		return {1, 1, 1};
	return players.at((unsigned int)index).getExactPos() + _moves[action];
}

std::array<std::pair<unsigned int, bomb::IPlayerController::Actions>, 4>
bomb::ai::AIController::getEnenemyDirections(
	std::array<bomb::game::Player, 4> &players, int index)
{
	std::array<std::pair<unsigned int, bomb::IPlayerController::Actions>, 4>
	        action;
	auto dists = getEnenemyDistances(players,index);
	auto myPos = players[index].getExactPos();
	for (unsigned int i = 0; i < players.size(); ++i) {
		action[i].first = dists.at(i).first;
		if (!players[action[i].first].isAlive() || (int)i == index) {
			action[i].second = IPlayerController::UNDEFINED;
			continue;
		}
		if (dists.at(i).second >= 0 && dists.at(i).second < 2 &&
			rand() % 2 < 1)
			action[i].second = IPlayerController::PUT_BOMB;
		else {
			auto hisPos = players[dists.at(i).first].getExactPos();
			action[i].second = vecToDir(hisPos - myPos);
		}
	}
	return action;
};

std::array<std::pair<unsigned int, float>, 4>
	bomb::ai::AIController::getEnenemyDistances(
	std::array<bomb::game::Player, 4> &players, int index)
{
	std::array<std::pair<unsigned int, float>, 4> dists{};
	dists.fill({0, -1});
	auto myPos = players[index].getExactPos();
	for (unsigned int i = 0; i < players.size(); ++i) {
		dists[i].first = i;
		if (i == (unsigned int)index || !players[i].isAlive())
			continue;
		auto hisPos = players[i].getExactPos();
		auto diff = myPos.getDistanceFrom(hisPos);
		dists[i].second = diff;
	}
	std::sort(dists.begin(), dists.end(), [](auto &a, auto &b) {
		return a.second > 0 && a.second < b.second;
	});
	return dists;
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



bomb::IPlayerController::Actions bomb::ai::AIController::searchSaferBlock(
	bomb::BomberMap &map, bomb::Map &safeMap, irr::core::vector2di vector2d)
{
	std::map<irr::core::vector2di, bomb::IPlayerController::Actions> dirs
		({{{vector2d.X, vector2d.Y - 1}, IPlayerController::MV_UP},
		  {{vector2d.X, vector2d.Y + 1}, IPlayerController::MV_DOWN},
		  {{vector2d.X - 1, vector2d.Y}, IPlayerController::MV_RIGHT},
		  {{vector2d.X + 1, vector2d.Y}, IPlayerController::MV_LEFT}});
	safeMap[vector2d] = (Map::BlockType) IPlayerController::PUT_BOMB;
	return searchSaferBlock(map, safeMap, dirs);
}

bomb::IPlayerController::Actions bomb::ai::AIController::searchSaferBlock(
	bomb::BomberMap &map, bomb::Map safeMap,
	std::map<irr::core::vector2di, IPlayerController::Actions> poses)
{
	std::map<irr::core::vector2di, IPlayerController::Actions> vec;
	if (poses.empty())
		return IPlayerController::UNDEFINED;
	for (auto tmp : poses) {
		for (auto &tmp2 : _moves) {
			if (map[tmp.first] != Map::EMPTY)
				continue;
			auto pos = tmp.first + irr::core::vector2di(
				static_cast<irr::s32>(tmp2.second.X),
				static_cast<irr::s32>(tmp2.second.Z));
			if (map[pos] == Map::EMPTY &&
				safeMap[pos] == Map::EMPTY) {
				vec[pos] = tmp.second;
				safeMap[pos] = (Map::BlockType) tmp.second;
				if (map.getBombRanges()[pos] == Map::EMPTY)
					return tmp.second;
			}
		}
	}
	return searchSaferBlock(map, safeMap, vec);
}

bool bomb::ai::AIController::isValidBombPlace(
	std::array<bomb::game::Player, 4> &players, bomb::BomberMap &map,
	int index)
{
	auto pos = players[index].getExactPos();
	std::vector<Map::BlockType> obj{
		map[irr::core::vector2df(pos.X, pos.Z - 1)],
		map[irr::core::vector2df(pos.X, pos.Z + 1)],
		map[irr::core::vector2df(pos.X - 1, pos.Z)],
		map[irr::core::vector2df(pos.X + 1, pos.Z)]};
	return find(obj.begin(), obj.end(), Map::BREAKABLE) != obj.end();
}
