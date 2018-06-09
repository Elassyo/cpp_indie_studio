//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// Bomb.hpp
//

#ifndef CPP_INDIE_STUDIO_BOMB_HPP
	#define CPP_INDIE_STUDIO_BOMB_HPP

	#include "../../Interface/IAssetManager.hpp"
	#include "../General/AActivator.hpp"
	#include "../General/Clock.hpp"

namespace bomb {
	namespace object {
		class Bomb : public bomb::game::AActivator {
		public:
			Bomb(IAssetManager &loader, bomb::game::Player
			&player, int playerIdx);

			const std::vector<std::pair<irr::core::vector2di,
				bomb::Map::BlockType>> &getBlast() const;
		private:
			int isActivable(bomb::Map &map,
				std::vector<std::pair<game::Player,
				PlayerActionner>> &vector) override;
			bool activate(bomb::Map &map,
				      bomb::game::Player &player,
				      IAssetManager &loader) override;
			bool deleteBlock(Map &map, irr::core::vector3di pos);
			bool blastLine(Map &map, irr::core::vector3di pos,
				       irr::core::vector2di iterator, int max);
			bomb::IAssetManager &_loader;
			std::unique_ptr<AnimatedObject> _model;
			std::vector<std::pair<irr::core::vector2di,
				bomb::Map::BlockType>> _blast;
			bomb::utils::Clock _timer;
			int _playerIdx;
		};
	}
}

#endif /* CPP_INDIE_STUDIO_BOMB_HPP */