//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// AIController.cpp
//

#include "AIController.hpp"
#include "../Exception/Exception.hpp"

bomb::player::AIController::AIController():
	APlayerController()
{
	_haveQuest = false;
}

void bomb::player::AIController::execute(const irr::core::vector2di &pos)
{
	accessBlock(pos);
	if (!_haveQuest || !isAccessible(_quest) || pos == _quest)
		initQuest();
	_action = astar(pos, _quest);
	if (rand() % 7 == 0)
		_action = PUT_BOMB;
}

bool bomb::player::AIController::isAccessible(const irr::core::vector2di &to)
{
	for (auto &e : _access)
		if (e == to)
			return true;
	return false;
}

void bomb::player::AIController::checkBorder(const irr::core::vector2di &from)
{
	if (!isWalkable(from))
		return;
	for (auto &e : _access)
		if (e == from)
			return;
	_access.push_back(from);
	checkBorder({from.X - 1, from.Y});
	checkBorder({from.X + 1, from.Y});
	checkBorder({from.X, from.Y - 1});
	checkBorder({from.X, from.Y + 1});
}

void bomb::player::AIController::accessBlock(const irr::core::vector2di &from)
{
	_access.clear();
	checkBorder(from);
}

void bomb::player::AIController::initQuest()
{
	if (_access.empty())
		throw bomb::Exception("AI", "Can't Move");
	_quest = _access[rand() % _access.size()];
}

bomb::IPlayerController::Actions
bomb::player::AIController::execAstar(std::vector<irr::core::vector2di> path,
	const irr::core::vector2di &last, const irr::core::vector2di &dest)
{
	bomb::IPlayerController::Actions a = NONE;

	if (last == dest)
		return UNDEFINED;
	if (!isAccessible(last))
		return NONE;
	for (auto &e : path)
		if (e == last)
			return NONE;
	path.push_back(last);
	a = execAstar(path, {last.X - 1, last.Y}, dest);
	if (a != NONE)
		return MV_LEFT;
	a = execAstar(path, {last.X + 1, last.Y}, dest);
	if (a != NONE)
		return MV_RIGHT;
	a = execAstar(path, {last.X, last.Y - 1}, dest);
	if (a != NONE)
		return MV_UP;
	a = execAstar(path, {last.X, last.Y + 1}, dest);
	if (a != NONE)
		return MV_DOWN;
	return NONE;
}

bomb::IPlayerController::Actions bomb::player::AIController::astar(
	const irr::core::vector2di &from,
	const irr::core::vector2di &to)
{
	std::vector<irr::core::vector2di> path;

	if (!isAccessible(to))
		return NONE;
	path.push_back(from);
	auto vec = to - from;
	if (std::abs(vec.X) > std::abs(vec.Y))
		return vec.X < 0 ? MV_LEFT : MV_RIGHT;
	else
		return vec.Y < 0 ? MV_UP : MV_DOWN;
}

bool bomb::player::AIController::isSafe(const irr::core::vector2di &pos)
{
	/* TODO check with bomb */
	return true;
}

bool bomb::player::AIController::isWalkable(const irr::core::vector2di &pos)
{
	/* TODO check with map */
	return (pos.X >= 0 && pos.Y >= 0 && pos.X < 15 && pos.Y < 15);
}
