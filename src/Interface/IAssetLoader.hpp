/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
** IAssetLoader.hpp
*/

#ifndef CPP_INDIE_STUDIO_IASSETLOADER_HPP
	#define CPP_INDIE_STUDIO_IASSETLOADER_HPP

	#include <memory>
	#include <irrlicht/irrlicht.h>
#include <src/Menu/Menu.hpp>

#include "../Audio/AudioFile.hpp"
	#include "../AnimatedObject.hpp"
	#include "../StaticObject.hpp"

namespace bomb {
	class IAssetLoader {
	public:
		virtual irr::gui::IGUIEnvironment *getGui() = 0;
		virtual irr::video::ITexture *loadTexture(
			const std::string &path) = 0;
		virtual std::unique_ptr<AudioFile> loadAudioFile(
			const std::string &path) = 0;
		virtual std::unique_ptr<bomb::AnimatedObject>
		        createAnimatedObject(const std::string &path,
			 irr::core::vector3df pos = {0, 0, 0},
			 irr::core::vector3df rot = {0, 0, 0},
			 irr::core::vector3df scale = {1, 1, 1}) = 0;
		virtual std::unique_ptr<bomb::StaticObject>
		        createStaticObject(const std::string &path,
			 irr::core::vector3df pos = {0, 0, 0},
			 irr::core::vector3df rot = {0, 0, 0},
			 irr::core::vector3df scale = {1, 1, 1}) = 0;
		virtual std::unique_ptr<menu::Menu> createMenu() = 0;
		virtual irr::scene::ICameraSceneNode *addCamera(
			const irr::core::vector3df &pos,
			const irr::core::vector3df &rot) = 0;
		virtual void deleteObject(std::unique_ptr<IObject>) = 0;
	};
}

#endif /* CPP_INDIE_STUDIO_IASSETLOADER_HPP */
