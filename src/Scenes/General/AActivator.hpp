//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// IActivator.hpp
//

#ifndef CPP_INDIE_STUDIO_IACTIVATOR_HPP
	#define CPP_INDIE_STUDIO_IACTIVATOR_HPP

	#include "../../Map/BomberMap.hpp"
	#include "Player.hpp"
	#include "../../Player/PlayerActionner.hpp"

namespace bomb {
	namespace game {
		class AActivator {
		public:
			AActivator();
			bool tryToActivate(bomb::BomberMap &map,
					   std::array<Player, 4> &players,
					   IAssetManager &loader);

		private:
			virtual int isActivable(bomb::BomberMap &map,
						std::array<Player, 4> &) = 0;
			virtual bool activate(bomb::BomberMap &map,
					      bomb::game::Player &player,
					      IAssetManager &loader) = 0;
			bool _activated;
		};
	}
}
#endif /* CPP_INDIE_STUDIO_IACTIVATOR_HPP */