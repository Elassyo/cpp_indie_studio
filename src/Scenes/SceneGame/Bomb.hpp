//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// Bomb.hpp
//

#ifndef CPP_INDIE_STUDIO_BOMB_HPP
	#define CPP_INDIE_STUDIO_BOMB_HPP

	#include "../../Interface/IAssetLoader.hpp"
	#include "../General/AActivator.hpp"
	#include "../General/Clock.hpp"

namespace bomb {
	namespace object {
		class Bomb : public bomb::game::AActivator {
		public:
			Bomb(IAssetLoader &loader,
				const irr::core::vector3df &pos, long time);

		protected:
			bool isActivable(game::Game &infos)
				override;
			bool activate(game::Game &infos) override;
			void setProperties(game::Game &infos, char idx);

		private:
			bomb::IAssetLoader &_loader;
			bomb::utils::Clock _timer;
			std::unique_ptr<AnimatedObject> _model;
		};
	}
}

#endif /* CPP_INDIE_STUDIO_BOMB_HPP */