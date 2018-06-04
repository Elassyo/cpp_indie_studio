//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// Map.hpp
//

#ifndef CPP_INDIE_STUDIO_MAP_HPP
	#define CPP_INDIE_STUDIO_MAP_HPP

	#include <memory>
	#include <vector>

	#include "../Interface/ISerializable.hpp"
	#include "../Interface/IRenderable.hpp"
	#include "../Map/MapWall.hpp"

namespace bomb {
	typedef std::pair<std::unique_ptr<bomb::MapWall>,
		irr::core::vector3di> MapCoord;

	class Map :
		virtual public ISerializable,
		virtual public IRenderable {
	public:
		void render() override;
		std::string toString() override;
	private:
		std::vector<bomb::MapCoord> _blocks;
	};
}

#endif /* CPP_INDIE_STUDIO_MAP_HPP */
