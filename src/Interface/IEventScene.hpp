/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
** IEventScene.hpp
*/

#ifndef CPP_INDIE_STUDIO_IEVENTSCENE_HPP
#define CPP_INDIE_STUDIO_IEVENTSCENE_HPP

#include <irrlicht/irrlicht.h>

namespace bomb {
	namespace scene {
		class IEventScene {
		public:
			virtual ~IEventScene() = default;
			virtual bool onEvent(const irr::SEvent& event) = 0;
		};
	}
}

#endif /* CPP_INDIE_STUDIO_IEVENTSCENE_HPP */