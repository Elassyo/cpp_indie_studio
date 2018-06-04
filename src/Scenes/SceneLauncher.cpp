//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// SceneLauncher.cpp
//

#include "SceneLauncher.hpp"
#include "../Exception/Exception.hpp"

bomb::scene::SceneLauncher::SceneLauncher(GameEngine &ge) :
		_gameEngine(ge)
{
	_scenes["game_test"] = std::make_shared<bomb::scene::SceneGame>();
}

void bomb::scene::SceneLauncher::launchScene(const std::string &sceneName)
{
	if (_scenes.find(sceneName) == _scenes.end())
		throw Exception("SceneLauncher", "Scenes " + sceneName +
						 " doesn't exist");
	std::shared_ptr<IGameScene> gs = _scenes[sceneName];
	SceneStatus sts = gs->start(_gameEngine);

	if (sts != BEGIN)
		throw Exception("SceneLauncher", "Cannot launch scene " + sceneName);
	while (gs->loop(_gameEngine) == CONTINUE) {
		_gameEngine.refresh();
	}
	std::string next = gs->nextScene();
	if (next.empty())
		return;
	launchScene(next);
}
