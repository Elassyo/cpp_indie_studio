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
	#include "../Audio/AudioBuffer.hpp"
	#include "../AnimatedObject.hpp"
	#include "../BillboardObject.hpp"
	#include "../CameraObject.hpp"
	#include "../PlaneObject.hpp"
	#include "../LightObject.hpp"
	#include "../StaticObject.hpp"

namespace bomb {
	class IAssetLoader {
	public:
		virtual ~IAssetLoader() = default;

		virtual irr::gui::IGUIEnvironment *getGui() = 0;
		virtual irr::video::ITexture *loadTexture(
			const std::string &path) = 0;
		virtual void loadAudioFile(const std::string &path) = 0;
		virtual irr::gui::IGUIFont *loadFont(
			const std::string &path) = 0;
		virtual std::unique_ptr<bomb::AnimatedObject>
		createAnimatedObject(
			const std::string &path,
			irr::core::vector3df pos = {0, 0, 0},
			irr::core::vector3df scale = {1, 1, 1},
			irr::core::vector3df rot = {0, 0, 0}) = 0;
		virtual std::unique_ptr<bomb::StaticObject>
		createStaticObject(
			const std::string &path,
			irr::core::vector3df pos = {0, 0, 0},
			irr::core::vector3df scale = {1, 1, 1},
			irr::core::vector3df rot = {0, 0, 0}) = 0;
		virtual std::unique_ptr<bomb::PlaneObject> createPlaneObject(
			irr::core::vector3df pos = {0, 0, 0},
			irr::core::vector3df scale = {1, 1, 1},
			irr::core::vector3df rot = {0, 0, 0}) = 0;
		virtual std::unique_ptr<BillboardObject> createBillboardObject(
			irr::core::vector3df pos = {0, 0, 0},
			irr::core::vector3df scale = {0, 0, 0},
			irr::core::vector3df rot = {0, 0, 0}
		) = 0;
		virtual std::unique_ptr<CameraObject> getCamera(
			const irr::core::vector3df &pos = {0, 0, 0},
			const irr::core::vector3df &rot = {0, 0, 0}) = 0;
		virtual std::unique_ptr<bomb::LightObject> createLightObject(
			const irr::core::vector3df &pos = {0, 0, 0},
			irr::video::SColorf col = {1.0f, 1.0f, 1.0f},
			float radius = 100.0f) = 0;
	};
}

#endif /* CPP_INDIE_STUDIO_IASSETLOADER_HPP */