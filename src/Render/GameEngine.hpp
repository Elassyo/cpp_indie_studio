//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// GameEngine.hpp
//

#ifndef CPP_INDIE_STUDIO_GAMEWINDOW_HPP
#define CPP_INDIE_STUDIO_GAMEWINDOW_HPP

#include <irrlicht/irrlicht.h>
#include "../AnimatedObject.hpp"
#include "../StaticObject.hpp"
#include "../Interface/IAssetLoader.hpp"

namespace bomb {
	class GameEngine : public IAssetLoader {
	public:
		GameEngine(const std::wstring &winName, uint x, uint y,
			   irr::video::E_DRIVER_TYPE);

		void refresh();

		irr::gui::IGUIEnvironment *loadGui() override;

		irr::video::ITexture *loadTexture(const std::string &) override;

		std::unique_ptr<bomb::AnimatedObject> getAnimatedObject
			(const std::string &path,
			 irr::core::vector3df pos, irr::core::vector3df rot,
			 irr::core::vector3df scale);
		std::unique_ptr<bomb::StaticObject> getStaticObject
			(const std::string &path,
			 irr::core::vector3df pos, irr::core::vector3df rot,
			 irr::core::vector3df scale);
		~GameEngine();
	private:
		std::unique_ptr<irr::IrrlichtDevice> _device;
		std::unique_ptr<irr::video::IVideoDriver> _videoDriver;
		std::unique_ptr<irr::scene::ISceneManager> _sceneManager;
	};
}
#endif /* CPP_INDIE_STUDIO_GAMEWINDOW_HPP */