//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// SceneLauncher.cpp
//

#include <iostream>
#include "SceneHomeMenu.hpp"

bomb::scene::SceneStatus bomb::scene::SceneHomeMenu::start(
	IAssetLoader &loader)
{
	std::cout << "button" << std::endl;
	_menu = loader.createMenu();
	_menu.get()->updateButtons(true);
	return BEGIN;
}

bomb::scene::SceneStatus
bomb::scene::SceneHomeMenu::loop(
	__attribute__((unused))bomb::IAssetLoader &loader)
{
	return CONTINUE;
}

void bomb::scene::SceneHomeMenu::save()
{
}

void bomb::scene::SceneHomeMenu::reset(__attribute__((unused))
				bomb::IAssetLoader &loader)
{
}

void bomb::scene::SceneHomeMenu::clean()
{
}

std::string bomb::scene::SceneHomeMenu::nextScene()
{
	return std::__cxx11::string();
}

bool bomb::scene::SceneHomeMenu::onEvent(__attribute__((unused))
				const irr::SEvent &event)
{
	return true;
}
