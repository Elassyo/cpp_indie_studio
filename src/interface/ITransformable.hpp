//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// ITransformable.hpp
//

#ifndef CPP_INDIE_STUDIO_ITRANSFORMABLE_HPP
#define CPP_INDIE_STUDIO_ITRANSFORMABLE_HPP

#include <irrlicht/vector3d.h>

namespace bomb {
	class ITransformable {
	public:
		virtual void move(const irr::core::vector3df &) = 0;
		virtual void rotate(const irr::core::vector3df &) = 0;
		virtual void scale(const irr::core::vector3df &) = 0;
		virtual ~ITransformable() = 0;
	};
}

#endif /* CPP_INDIE_STUDIO_ITRANSFORMABLE_HPP */