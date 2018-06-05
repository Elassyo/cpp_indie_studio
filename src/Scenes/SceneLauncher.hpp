//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// SceneLauncher.hpp
//

#ifndef CPP_INDIE_STUDIO_SCENELAUNCHER_HPP
	#define CPP_INDIE_STUDIO_SCENELAUNCHER_HPP

	#include <iostream>
	#include <map>
	
	#include "../Exception/Exception.hpp"
	#include "../Interface/IGameScene.hpp"
	#include "../Render/GameEngine.hpp"
	#include "SceneGame/SceneGame.hpp"
	#include "SceneHomeMenu/SceneHomeMenu.hpp"

namespace bomb {
	namespace scene {
		class SceneLauncher {
		public:
			explicit SceneLauncher(GameEngine &);

			void launchScene(const std::string &);

		private:
			GameEngine & _gameEngine;
			std::map<std::string, std::shared_ptr<IGameScene>>
				_scenes;
		};
	}
}

#endif /* CPP_INDIE_STUDIO_SCENELAUNCHER_HPP */