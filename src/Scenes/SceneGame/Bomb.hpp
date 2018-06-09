//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// Bomb.hpp
//

#ifndef CPP_INDIE_STUDIO_BOMB_HPP
	#define CPP_INDIE_STUDIO_BOMB_HPP

	#include "../../Interface/IAssetLoader.hpp"
	#include "../General/AActivator.hpp"
	#include "../General/Clock.hpp"

namespace bomb {
	namespace object {
		class Bomb : public bomb::game::AActivator {
		public:
			Bomb(IAssetLoader &loader, bomb::game::Player
			&player, int playerIdx);

		protected:
			int isActivable(bomb::Map &map,
				std::vector<std::pair<game::Player,
				PlayerActionner>> &vector) override;

			bool activate(bomb::Map &map,
				bomb::game::Player &player) override;

		private:
			bomb::IAssetLoader &_loader;
			bomb::utils::Clock _timer;
			std::unique_ptr<AnimatedObject> _model;
			int _playerIdx;

			bool deleteBlock(Map &map, irr::core::vector3df pos);
		};
	}
}

#endif /* CPP_INDIE_STUDIO_BOMB_HPP */