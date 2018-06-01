/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
** IAssetLoader.hpp
*/

#ifndef CPP_INDIE_STUDIO_IASSETLOADER_HPP
#define CPP_INDIE_STUDIO_IASSETLOADER_HPP

#include <irrlicht/irrlicht.h>
#include <iostream>
#include <memory>

namespace bomb {
	class IAssetLoader {
	public:
		virtual irr::gui::IGUIEnvironment * loadGui()
		= 0;
		virtual irr::video::ITexture * loadTexture
			(const std::string &) = 0;
	};
}

#endif /* CPP_INDIE_STUDIO_IASSETLOADER_HPP */