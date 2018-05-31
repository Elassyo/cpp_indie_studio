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
		virtual std::unique_ptr<irr::gui::IGUIEnvironment> loadGui()
		= 0;
		virtual std::unique_ptr<irr::video::ITexture> loadTexture
			(const std::string &) = 0;
	};
}

#endif /* CPP_INDIE_STUDIO_IASSETLOADER_HPP */