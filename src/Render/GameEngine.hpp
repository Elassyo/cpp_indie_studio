//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// GameEngine.hpp
//

#ifndef CPP_INDIE_STUDIO_GAMEENGINE_HPP
	#define CPP_INDIE_STUDIO_GAMEENGINE_HPP

	#include <memory>
	#include <irrlicht/irrlicht.h>
	#include "../Audio/AudioDevice.hpp"
	#include "../Interface/IAssetLoader.hpp"
	#include "../Interface/IRenderWindow.hpp"
	#include "../AnimatedObject.hpp"
	#include "../StaticObject.hpp"
	#include "EventHandler.hpp"

namespace bomb {
	class GameEngine : virtual public IAssetLoader, virtual public
		IRenderWindow {
	public:
		GameEngine(const std::wstring &winName, uint x, uint h,
			   irr::video::E_DRIVER_TYPE);
		~GameEngine();

		void refresh() override;
		irr::gui::IGUIEnvironment *loadGui() override;
		irr::video::ITexture *loadTexture(const std::string &) override;
		std::unique_ptr<bomb::AnimatedObject> createAnimatedObject
			(const std::string &path,
			 irr::core::vector3df pos, irr::core::vector3df rot,
			 irr::core::vector3df scale) override;
		std::unique_ptr<bomb::StaticObject> createStaticObject
			(const std::string &path,
			 irr::core::vector3df pos, irr::core::vector3df rot,
			 irr::core::vector3df scale) override;
		void deleteObject(std::unique_ptr<IObject>) override;
		void addCamera(const irr::core::vector3df &pos,
			       const irr::core::vector3df &rot) override;
		void listenEventScene(std::shared_ptr<scene::IEventScene>);
		bool isRunning();

	private:
		EventHandler _evtHandler;
		irr::IrrlichtDevice *_device;
		irr::video::IVideoDriver *_videoDriver;
		irr::scene::ISceneManager *_sceneManager;
		irr::scene::ICameraSceneNode *_camera;
		std::unique_ptr<AudioDevice> _audioDev;
	};
}
#endif /* CPP_INDIE_STUDIO_GAMEENGINE_HPP */
