//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// SceneLauncher.cpp
//

#include "SceneHomeMenu.hpp"

bomb::scene::SceneHomeMenu::SceneHomeMenu(bomb::PersistentInfo &_infos)
	: AScene(_infos) {}

bomb::scene::SceneStatus bomb::scene::SceneHomeMenu::start(
	IAssetManager &loader)
{
	launchMainMusic(loader);
	_running = true;
	_cam = loader.getCamera();
	_menu.createMenu(loader);
	_menu.addImage(loader.loadTexture("images/menuBack.png"), {.5f, .5f}, 5);
	_menu.setElementSize(5, {1, 1});
	_menu.addText(L"SUPER\nBOMBERMARIO\nBROS.", {.5f, .15f}, 0);
	_menu.setElementFont(0, menu::TITLE);
	addButtons();
	_menu.updateButtons(loader, true);
	return BEGIN;
}

void bomb::scene::SceneHomeMenu::addButtons()
{
	_menu.addButton(L"Play", {.5f, .35f}, 1);
	_menu.setButtonEvent(1, [this](){
		_nextScene = "character_scene";
	});
	_menu.addButton(L"Options", {.5f, .5f}, 2);
	_menu.setButtonEvent(2, [this](){
		_nextScene = "option_scene";
	});
	_menu.addButton(L"Quit", {.5f, .65f}, 3);
	_menu.setButtonEvent(3, [this](){
		_cam->playSound("sfx/thwomp.ogg");
		std::this_thread::sleep_for(std::chrono::seconds(1));
		_nextScene = "";
	});
}

void bomb::scene::SceneHomeMenu::launchMainMusic(IAssetManager &loader)
{
	loader.loadAudioFile("sfx/thwomp.ogg");
	if (!_infos.MainMusic()) {
		loader.loadAudioFile(
			"music/mario-and-luigi-partners-in-time.ogg");
		loader.playMusic("music/mario-and-luigi-partners-in-time.ogg");
		_infos.setMainMusic(true);
	}

}

bomb::scene::SceneStatus bomb::scene::SceneHomeMenu::loop(
	bomb::IAssetManager &loader)
{
	_menu.updateButtons(loader, true);
	return _running ? CONTINUE : END;
}

void bomb::scene::SceneHomeMenu::save()
{
}

void bomb::scene::SceneHomeMenu::reset(bomb::IAssetManager &loader)
{
	(void) loader;
}

void bomb::scene::SceneHomeMenu::clean(IAssetManager &loader)
{
	if (_nextScene.empty())
		loader.stopAll();
	_menu.clean();
	(void) loader;
}

std::string bomb::scene::SceneHomeMenu::nextScene()
{
	return _nextScene;
}

bool bomb::scene::SceneHomeMenu::onEvent(const irr::SEvent &event)
{
	if (event.EventType == irr::EET_MOUSE_INPUT_EVENT)
		return false;
	if (_menu.handleEvent(event))
		_running = false;
	return true;
}
