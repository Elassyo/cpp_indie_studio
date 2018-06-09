//
// EPITECH PROJECT, 2018
// cpp_indie_studio - BombDown.hpp
// File description:
// Created by Gregory EPLE
//

#ifndef CPP_INDIE_STUDIO_BOMBDOWN_HPP
	#define CPP_INDIE_STUDIO_BOMBDOWN_HPP

	#include "Power.hpp"

namespace bomb {
	namespace object {
		class BombDown : public bomb::object::Power {
		public:
			BombDown(bomb::IAssetManager &loader,
				 const irr::core::vector3df &pos);

		private:
			void addPower(bomb::game::Player &player) override;
		};
	}
}

#endif //CPP_INDIE_STUDIO_BombDown_HPP
