//
// EPITECH PROJECT, 2018
// cpp_indie_studio - BombUp.hpp
// File description:
// Created by Gregory EPLE
//

#ifndef CPP_INDIE_STUDIO_BOMBUP_HPP
	#define CPP_INDIE_STUDIO_BOMBUP_HPP

	#include "Power.hpp"

namespace bomb {
	namespace object {
		class BombUp : public Power {
		public:
			BombUp(bomb::IAssetManager &loader,
			       const irr::core::vector3df &pos);

		private:
			void addPower(bomb::game::Player &player) override;

		};
	}
}

#endif //CPP_INDIE_STUDIO_BombUp_HPP
