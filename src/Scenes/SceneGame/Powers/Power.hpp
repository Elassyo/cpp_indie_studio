//
// EPITECH PROJECT, 2018
// cpp_indie_studio - Power.hpp
// File description:
// Created by Gregory EPLE
//

#ifndef CPP_INDIE_STUDIO_POWER_HPP
	#define CPP_INDIE_STUDIO_POWER_HPP

	#include "../../General/AActivator.hpp"

namespace bomb {
	namespace object {
		class Power : public game::AActivator {
		public:
			Power(bomb::IAssetLoader &loader,
			      const irr::core::vector3df &pos,
			      std::string path);
			bool isActivable(game::GameInfo &infos)	override;
			bool activate(game::GameInfo &infos) override;

		protected:
			bomb::IAssetLoader &_loader;
			std::unique_ptr<StaticObject> _model;
		};
	}
}

#endif //CPP_INDIE_STUDIO_POWER_HPP
