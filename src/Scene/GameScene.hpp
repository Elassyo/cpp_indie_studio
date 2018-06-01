//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// GameScene.hpp
//

#ifndef CPP_INDIE_STUDIO_GAMESCENE_HPP
#define CPP_INDIE_STUDIO_GAMESCENE_HPP

#include <vector>
#include "../Render/GameEngine.hpp"

namespace bomb {
	namespace scene {
		class GameScene {
		public:
			explicit GameScene(GameEngine &);
			void gameLoop();
		private:
			GameEngine &_gameEngine;
			std::vector<std::unique_ptr<AnimatedObject>> _anims;
			std::vector<std::unique_ptr<StaticObject>> _statics;
		};
	}
}

#endif /* CPP_INDIE_STUDIO_GAMESCENE_HPP */