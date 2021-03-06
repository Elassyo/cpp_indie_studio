//
// EPITECH PROJECT, 2018
// cpp_indie_studio - SpeedUp.hpp
// File description:
// Created by Gregory EPLE
//

#ifndef CPP_INDIE_STUDIO_SPEEDUP_HPP
	#define CPP_INDIE_STUDIO_SPEEDUP_HPP

	#include "Power.hpp"

namespace bomb {
	namespace object {
		class SpeedUp : public Power {
		public:
			SpeedUp(bomb::IAssetManager &loader,
				const irr::core::vector3df &pos);

		private:
			void addPower(bomb::game::Player &player) override;
		};
	}
}

#endif //CPP_INDIE_STUDIO_SpeedUp_HPP
