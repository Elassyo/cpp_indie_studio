//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// IRenderable.hpp
//

#ifndef CPP_INDIE_STUDIO_IRENDERABLE_HPP
	#define CPP_INDIE_STUDIO_IRENDERABLE_HPP

	#include "src/Render/GameWindow.hpp"

namespace bomb {
	class IRenderable {
	public:
		virtual void render(const bomb::GameWindow &) = 0;
		virtual ~IRenderable() = default;
	};
}

#endif /* CPP_INDIE_STUDIO_IRENDERABLE_HPP */
