//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// SceneLauncher.cpp
//

#include "SceneLauncher.hpp"
#include "SceneKeyMenu/SceneKeyMenu.hpp"

bomb::scene::SceneLauncher::SceneLauncher(GameEngine &ge) :
	_gameEngine(ge)
{
	_scenes["game_scene"] =
		std::make_shared<bomb::scene::SceneGame>(_info);
	_scenes["home_scene"] =
		std::make_shared<bomb::scene::SceneHomeMenu>(_info);
	_scenes["option_scene"] =
		std::make_shared<bomb::scene::SceneOptionMenu>(_info);
	_scenes["character_scene"] =
		std::make_shared<bomb::scene::SceneCharacterMenu>(_info);
	_scenes["key_scene"] =
		std::make_shared<bomb::scene::SceneKeyMenu>(_info);
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
	bool running = _loopScene(scene);
	scene->clean(_gameEngine);
	_gameEngine.listenEventScene(nullptr);
	std::string next = scene->nextScene();
	if (!next.empty() && running)
		launchScene(next);
}

bool bomb::scene::SceneLauncher::_loopScene
	(std::shared_ptr<bomb::scene::IGameScene> &scene)
{
	utils::Clock clock(0);
	bool running = _gameEngine.isRunning();
	while (running && scene->loop(_gameEngine) == CONTINUE)
	{
		clock.reset();
		_gameEngine.refresh();
		if (clock.getElapsedTime() < 16)
			std::this_thread::sleep_for
			(std::chrono::microseconds(16 - clock.getElapsedTime()));
		running = _gameEngine.isRunning();
	}
	return running;
}
