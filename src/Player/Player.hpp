//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// Player.hpp
//

#ifndef CPP_INDIE_STUDIO_PLAYER_HPP
#define CPP_INDIE_STUDIO_PLAYER_HPP

#include <memory>
#include "../AnimatedObject.hpp"
#include "../Interface/IAssetLoader.hpp"

namespace bomb {
	class Player {
	public:
		Player(
			IAssetLoader &loader,
			const std::string &path,
			const irr::core::vector3df &pos,
			const irr::core::vector3df &scale,
			const irr::core::vector3df &rotation,
			const irr::core::vector3di &mapPos
		);

	private:
		std::unique_ptr<AnimatedObject> _obj;
		irr::core::vector3di _mapPos;
	};
}

#endif /* CPP_INDIE_STUDIO_PLAYER_HPP */