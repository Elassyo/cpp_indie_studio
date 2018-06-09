//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// IActivator.cpp
//

#include "AActivator.hpp"

bomb::game::AActivator::AActivator() : _activated(false) {}

bool bomb::game::AActivator::tryToActivate(bomb::Map &map,
	std::vector<std::pair<Player, PlayerActionner>> &players)
{
	if (!_activated) {
		auto idx = isActivable(map, players);
		if (idx < 0)
			return _activated;
		_activated = activate(map, players.at(
			static_cast<unsigned long>(idx)).first);
	}
	return _activated;
}
