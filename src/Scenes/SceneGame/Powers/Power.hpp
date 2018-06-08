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
			int isActivable(bomb::Map &map,
					std::vector<std::pair<game::Player,
						PlayerActionner>>
					&vector) override;
			bool activate(bomb::Map &map,
				      bomb::game::Player &player) override;

		private:
			bomb::IAssetLoader &_loader;
			std::unique_ptr<StaticObject> _model;
		};
	}
}

#endif //CPP_INDIE_STUDIO_POWER_HPP
