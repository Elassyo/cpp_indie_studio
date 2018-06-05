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
	_menu->addButton([]() { std::cout << "zzddzdded" << std::endl; },
		L"COUCOU", { 0.5, 0.5 });
	return BEGIN;
}

bomb::scene::SceneStatus bomb::scene::SceneHomeMenu::loop(
	bomb::IAssetLoader &loader)
{
	_menu.get()->updateButtons(true);
	return CONTINUE;
}

void bomb::scene::SceneHomeMenu::save()
{
}

void bomb::scene::SceneHomeMenu::reset(bomb::IAssetLoader &loader)
{
}

void bomb::scene::SceneHomeMenu::clean()
{
}

std::string bomb::scene::SceneHomeMenu::nextScene()
{
	return "";
}

bool bomb::scene::SceneHomeMenu::onEvent(const irr::SEvent &event)
{
	return true;
}
