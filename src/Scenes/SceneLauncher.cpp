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
	_loopScene(scene);
	_gameEngine.listenEventScene(nullptr);
	std::string next = scene->nextScene();
	if (!next.empty())
		launchScene(next);
}

void bomb::scene::SceneLauncher::_loopScene
	(std::shared_ptr<bomb::scene::IGameScene> &scene)
{
	utils::Clock clock(0);
	while (scene->loop(_gameEngine) == CONTINUE && _gameEngine.isRunning())
	{
		clock.reset();
		_gameEngine.refresh();
		if (clock.getElapsedTime() < 16)
			std::this_thread::sleep_for
			(std::chrono::microseconds(16 - clock.getElapsedTime()));
	}
}
