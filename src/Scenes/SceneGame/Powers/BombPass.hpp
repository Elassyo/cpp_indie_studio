//
// EPITECH PROJECT, 2018
// cpp_indie_studio - BombPass.hpp
// File description:
// Created by Gregory EPLE
//

#ifndef CPP_INDIE_STUDIO_BOMBPASS_HPP
	#define CPP_INDIE_STUDIO_BOMBPASS_HPP

	#include "Power.hpp"

namespace bomb {
	namespace object {
		class BombPass : public Power {
		public:
			BombPass(bomb::IAssetManager &loader,
				 const irr::core::vector3df &pos);

		private:
			void addPower(bomb::game::Player &player) override;
		};
	}
}

#endif //CPP_INDIE_STUDIO_BombPass_HPP
