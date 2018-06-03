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
#include "../Interface/IRenderWindow.hpp"

namespace bomb {
	class GameEngine : virtual public IAssetLoader, virtual public
		IRenderWindow{
	public:
		GameEngine(const std::wstring &winName, uint x, uint y,
			   irr::video::E_DRIVER_TYPE);

		void refresh();

		irr::gui::IGUIEnvironment *loadGui() override;

		irr::video::ITexture *loadTexture(const std::string &) override;

		std::unique_ptr<bomb::AnimatedObject> getAnimatedObject
			(const std::string &path,
			 irr::core::vector3df pos, irr::core::vector3df rot,
			 irr::core::vector3df scale) override;
		std::unique_ptr<bomb::StaticObject> getStaticObject
			(const std::string &path,
			 irr::core::vector3df pos, irr::core::vector3df rot,
			 irr::core::vector3df scale) override;
		void deleteObject(std::unique_ptr<IObject>);
		void addCamera(const irr::core::vector3df &pos,
			       const irr::core::vector3df &rot) override;
		~GameEngine();
	private:
		irr::IrrlichtDevice *_device;
		irr::video::IVideoDriver *_videoDriver;
		irr::scene::ISceneManager *_sceneManager;
		irr::scene::ICameraSceneNode *_camera;
	};
}
#endif /* CPP_INDIE_STUDIO_GAMEWINDOW_HPP */