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
	_scenes["home_scene"] = std::make_shared<bomb::scene::SceneHomeMenu>();
}

void bomb::scene::SceneLauncher::launchScene(const std::string &name)
{
	auto it = _scenes.find(name);
	if (it == _scenes.end())
		throw Exception("SceneLauncher",
			"Scene " + name + " doesn't exist");
	std::shared_ptr<IGameScene> scene = it->second;
	if (scene->start(_gameEngine) != BEGIN)
		throw Exception("SceneLauncher",
			"Failed to launch scene " + name);
	_gameEngine.listenEventScene(scene);
	while (scene->loop(_gameEngine) == CONTINUE && _gameEngine.isRunning())
		_gameEngine.refresh();
	_gameEngine.listenEventScene(nullptr);
	std::string next = scene->nextScene();
	if (!next.empty())
		launchScene(next);
}
