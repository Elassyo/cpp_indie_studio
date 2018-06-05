//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// SceneLauncher.cpp
//

#include "SceneLauncher.hpp"

bomb::scene::SceneLauncher::SceneLauncher(GameEngine &ge) :
		_gameEngine(ge)
{
	_scenes["game_scene"] = std::make_shared<bomb::scene::SceneGame>();
	_scenes["home_menu"] = std::make_shared<bomb::scene::SceneHomeMenu>();
}

void bomb::scene::SceneLauncher::launchScene(const std::string &sceneName)
{
	if (_scenes.find(sceneName) == _scenes.end())
		throw Exception("SceneLauncher", "Scenes " + sceneName +
						 " doesn't exist");
	std::shared_ptr<IGameScene> gs = _scenes[sceneName];
	SceneStatus sts = gs->start(_gameEngine);
	if (sts != BEGIN)
		throw Exception("SceneLauncher", "Cannot launch scene "
				+ sceneName);
	while (gs->loop(_gameEngine) == CONTINUE) {
		if (!_gameEngine.isRunning())
			break;
		_gameEngine.refresh();
	}
	std::string next = gs->nextScene();
	if (next.empty())
		return;
	launchScene(next);
}
