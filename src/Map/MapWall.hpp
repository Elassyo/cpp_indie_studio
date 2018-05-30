//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// MapWall.hpp
//

#ifndef CPP_INDIE_STUDIO_MAPWALL_HPP
#define CPP_INDIE_STUDIO_MAPWALL_HPP

#include "../AObject.hpp"

namespace bomb {
	class MapWall :
		public AObject {
	public:
		enum Status {
			UNBREAKABLE,
			BREAKABLE
		};

		explicit MapWall(
			const irr::core::vector3df &pos,
			const irr::core::vector3df &scale,
			const irr::core::vector3df &rotation,
			Status status,
			size_t hp = 1
		);
		MapWall(const MapWall &ex);

		bool bomb(size_t damage = 1);
		size_t getHp() const;
		void setHp(size_t hp);

	private:
		Status _status;
		size_t _hp;
	};
}

#endif /* CPP_INDIE_STUDIO_MAPWALL_HPP */
