//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// SceneLauncher.hpp
//

#ifndef CPP_INDIE_STUDIO_SCENELAUNCHER_HPP
#define CPP_INDIE_STUDIO_SCENELAUNCHER_HPP

#include "../Render/GameEngine.hpp"
#include "../Interface/IGameScene.hpp"
#include "SceneGame.hpp"
#include <iostream>
#include <unordered_map>

namespace bomb {
	namespace scene {
		class SceneLauncher {
		public:
			explicit SceneLauncher(GameEngine &);
			void launchScene(const std::string &);
		private:
			GameEngine &_gameEngine;
			std::unordered_map
				<std::string, std::shared_ptr<IGameScene>>
				_scenes;
		};
	}
}

#endif /* CPP_INDIE_STUDIO_SCENELAUNCHER_HPP */