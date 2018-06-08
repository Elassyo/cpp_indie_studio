//
// EPITECH PROJECT, 2018
// cpp_indie_studio - BombFull.hpp
// File description:
// Created by Gregory EPLE
//

#ifndef CPP_INDIE_STUDIO_BOMBFULL_HPP
	#define CPP_INDIE_STUDIO_BOMBFULL_HPP

	#include "Power.hpp"

namespace bomb {
	namespace object {
		class BombFull : public bomb::object::Power {
		public:
			BombFull(bomb::IAssetLoader &loader,
				const irr::core::vector3df &pos);
			bool activate(game::Game &infos) override;
		};
	}
}

#endif //CPP_INDIE_STUDIO_BombFull_HPP
