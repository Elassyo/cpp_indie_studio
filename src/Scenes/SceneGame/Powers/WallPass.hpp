//
// EPITECH PROJECT, 2018
// cpp_indie_studio - WallPass.hpp
// File description:
// Created by Gregory EPLE
//

#ifndef CPP_INDIE_STUDIO_WALLPASS_HPP
	#define CPP_INDIE_STUDIO_WALLPASS_HPP

	#include "Power.hpp"

namespace bomb {
	namespace object {
		class WallPass : public Power {
		public:
			WallPass(bomb::IAssetManager &loader,
				 const irr::core::vector3df &pos);

		private:
			void addPower(bomb::game::Player &player) override;
		};
	}
}

#endif //CPP_INDIE_STUDIO_WallPass_HPP
