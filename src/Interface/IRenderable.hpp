//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// IRenderable.hpp
//

#ifndef CPP_INDIE_STUDIO_IRENDERABLE_HPP
	#define CPP_INDIE_STUDIO_IRENDERABLE_HPP

namespace bomb {
	class IRenderable {
	public:
		virtual ~IRenderable() = default;

		virtual void render() = 0;
	};
}

#endif /* CPP_INDIE_STUDIO_IRENDERABLE_HPP */
