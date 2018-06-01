//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// MapWall.hpp
//

#ifndef CPP_INDIE_STUDIO_MAPWALL_HPP
#define CPP_INDIE_STUDIO_MAPWALL_HPP

#include "../StaticObject.hpp"

namespace bomb {
	class MapWall {
	public:
		enum Status {
			UNBREAKABLE,
			BREAKABLE
		};

		explicit MapWall(StaticObject &,
				 bomb::MapWall::Status status, size_t hp);
		bool bomb(size_t damage = 1);
		size_t getHp() const;
		void setHp(size_t hp);

	private:
		Status _status;
		size_t _hp;
		StaticObject &_obj;

	};
}

#endif /* CPP_INDIE_STUDIO_MAPWALL_HPP */
