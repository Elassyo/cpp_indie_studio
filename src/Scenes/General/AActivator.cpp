//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// IActivator.cpp
//


#include "AActivator.hpp"

bomb::game::AActivator::AActivator() : _activated(false) {}

bool bomb::game::AActivator::tryToActivate(bomb::game::GameInfo &infos,
					bomb::Map &map)
{
	if (!_activated && isActivable(infos, map))
		_activated = activate(infos, map);
	return _activated;
}
