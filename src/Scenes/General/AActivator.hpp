//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// IActivator.hpp
//

#ifndef CPP_INDIE_STUDIO_IACTIVATOR_HPP
	#define CPP_INDIE_STUDIO_IACTIVATOR_HPP

	#include "../../Map/Map.hpp"
	#include "Player.hpp"
	#include "../../Player/PlayerActionner.hpp"

namespace bomb {
	namespace game {
		class AActivator {
		public:
			AActivator();
			bool tryToActivate(bomb::Map &map,
				std::vector<std::pair<Player, PlayerActionner>>
				&players, IAssetManager &loader);

		private:
			virtual int isActivable(bomb::Map &map, std::vector
				<std::pair<Player, PlayerActionner>> &) = 0;
			virtual bool activate(bomb::Map &map,
					      bomb::game::Player &player,
					      IAssetManager &loader) = 0;
			bool _activated;
		};
	}
}
#endif /* CPP_INDIE_STUDIO_IACTIVATOR_HPP */