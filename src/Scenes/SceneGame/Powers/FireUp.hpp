//
// EPITECH PROJECT, 2018
// cpp_indie_studio - FireUp.hpp
// File description:
// Created by Gregory EPLE
//

#ifndef CPP_INDIE_STUDIO_FIREUP_HPP
	#define CPP_INDIE_STUDIO_FIREUP_HPP

	#include "Power.hpp"

namespace bomb {
	namespace object {
		class FireUp : public Power {
		public:
			FireUp(bomb::IAssetLoader &loader,
			       const irr::core::vector3df &pos);

		private:
			bool activate(bomb::Map &map,
				      bomb::game::Player &player) override;
		};
	}
}

#endif //CPP_INDIE_STUDIO_FireUp_HPP
