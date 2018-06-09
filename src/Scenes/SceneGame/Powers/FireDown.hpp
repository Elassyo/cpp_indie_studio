//
// EPITECH PROJECT, 2018
// cpp_indie_studio - FireDown.hpp
// File description:
// Created by Gregory EPLE
//

#ifndef CPP_INDIE_STUDIO_FIREDOWN_HPP
	#define CPP_INDIE_STUDIO_FIREDOWN_HPP

	#include "Power.hpp"

namespace bomb {
	namespace object {
		class FireDown : public Power {
		public:
			FireDown(bomb::IAssetManager &loader,
				 const irr::core::vector3df &pos);

		private:
			void addPower(bomb::game::Player &player) override;

		};
	}
}

#endif //CPP_INDIE_STUDIO_FireDown_HPP
