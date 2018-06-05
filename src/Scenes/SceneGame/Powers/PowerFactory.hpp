//
// EPITECH PROJECT, 2018
// cpp_indie_studio - PowerFactory.hpp
// File description:
// Created by Gregory EPLE
//

#ifndef CPP_INDIE_STUDIO_POWERFACTORY_HPP
	#define CPP_INDIE_STUDIO_POWERFACTORY_HPP

	#include "Power.hpp"

	#include "BombUp.hpp"

	#include "BombDown.hpp"

	#include "FireUp.hpp"

	#include "SpeedUp.hpp"

	#include "FireDown.hpp"

	#include "SpeedDown.hpp"

	#include "WallPass.hpp"

	#include "BombPass.hpp"

namespace bomb {
	namespace object {
		class PowerFactory {
		public:
			PowerFactory();
			std::unique_ptr<bomb::object::Power> getRandomPower(
				bomb::IAssetLoader &loader,
				const irr::core::vector3df &pos);

		private:
			template<class T> std::unique_ptr<Power>
			createPtr(bomb::IAssetLoader &loader,
				  const irr::core::vector3df &pos);
			std::vector<std::pair<std::unique_ptr<Power>
			(bomb::object::PowerFactory::*)
				(bomb::IAssetLoader &,
				 const irr::core::vector3df &), int>> _powers;
			int _total;
		};
	}
}

#endif //CPP_INDIE_STUDIO_POWERFACTORY_HPP
