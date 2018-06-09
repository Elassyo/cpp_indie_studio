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
			Bomb(const Bomb &);

			void setLoader(IAssetManager &_loader);
			void setModel(std::unique_ptr<AnimatedObject> &_model);
			void
			setBlast(const std::vector<
				std::pair<irr::core::vector2di,
					bomb::Map::BlockType>> &b);
			void setTimer(const utils::Clock &_timer);
			void setPlayerIdx(int _playerIdx);

			IAssetManager &getLoader() const;
			const std::unique_ptr<AnimatedObject> &getModel() const;
			const
			std::vector<std::pair<irr::core::vector2di,
				bomb::Map::BlockType>> &getBlast() const;
			const utils::Clock &getTimer() const;
			int getPlayerIdx() const;

		private:
			int isActivable(bomb::Map &map,
				std::vector<std::pair<game::Player,
				PlayerActionner>> &vector) override;

			bool activate(bomb::Map &map,
				bomb::game::Player &player) override;
			bomb::IAssetManager &_loader;
			std::unique_ptr<AnimatedObject> _model;
			std::vector<std::pair<irr::core::vector2di,
				bomb::Map::BlockType>> _blast;
			bomb::utils::Clock _timer;
			int _playerIdx;

			bool deleteBlock(Map &map, irr::core::vector3df pos);
		};
	}
}

#endif /* CPP_INDIE_STUDIO_BOMB_HPP */