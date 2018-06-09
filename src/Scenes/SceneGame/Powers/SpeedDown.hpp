//
// EPITECH PROJECT, 2018
// cpp_indie_studio - SpeedDown.hpp
// File description:
// Created by Gregory EPLE
//

#ifndef CPP_INDIE_STUDIO_SPEEDDOWN_HPP
	#define CPP_INDIE_STUDIO_SPEEDDOWN_HPP

	#include "Power.hpp"

namespace bomb {
	namespace object {
		class SpeedDown : public Power {
		public:
			SpeedDown(bomb::IAssetManager &loader,
				  const irr::core::vector3df &pos);

		private:
			void addPower(bomb::game::Player &player) override;
		};
	}
}

#endif //CPP_INDIE_STUDIO_SpeedDown_HPP
