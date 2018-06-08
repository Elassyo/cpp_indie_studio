//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// EventHandler.cpp
//

#include <iostream>
#include "EventHandler.hpp"

void bomb::EventHandler::injectScene
	(std::shared_ptr<bomb::scene::IEventScene> scene)
{
	_evtScene = scene;
}

bool bomb::EventHandler::OnEvent(const irr::SEvent &event)
{
	if (_evtScene)
		return _evtScene->onEvent(event);
	return false;
}
