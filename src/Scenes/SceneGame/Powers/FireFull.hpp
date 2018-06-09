//
// EPITECH PROJECT, 2018
// cpp_indie_studio - FireFull.hpp
// File description:
// Created by Gregory EPLE
//

#ifndef CPP_INDIE_STUDIO_FIREFULL_HPP
	#define CPP_INDIE_STUDIO_FIREFULL_HPP

	#include "Power.hpp"

namespace bomb {
	namespace object {
		class FireFull : public Power {
		public:
			FireFull(bomb::IAssetLoader &loader,
				 const irr::core::vector3df &pos);

		private:
			bool activate(bomb::Map &map,
				      bomb::game::Player &player) override;
		};
	}
}

#endif //CPP_INDIE_STUDIO_FireFull_HPP
