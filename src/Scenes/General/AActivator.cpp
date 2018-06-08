//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// IActivator.cpp
//

#include "AActivator.hpp"

bomb::game::AActivator::AActivator() : _activated(false) {}

bool bomb::game::AActivator::tryToActivate(bomb::Map &map,
					   std::vector<Player> &player)
{
	if (!_activated && isActivable(map, player))
		_activated = activate(map, player);
	return _activated;
}
