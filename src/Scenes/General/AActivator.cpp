//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// IActivator.cpp
//

#include "AActivator.hpp"

bomb::game::AActivator::AActivator() : _activated(false) {}

bool bomb::game::AActivator::tryToActivate(bomb::game::Game &infos)
{
	if (!_activated && isActivable(infos))
		_activated = activate(infos);
	return _activated;
}
