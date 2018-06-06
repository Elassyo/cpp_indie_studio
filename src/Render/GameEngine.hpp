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
	#include "../Version.hpp"
	#include "EventHandler.hpp"

namespace bomb {
	class GameEngine : virtual public IAssetLoader, virtual public
		IRenderWindow {
	public:
		GameEngine(const std::wstring &winName, unsigned int x, unsigned int h,
			   irr::video::E_DRIVER_TYPE);
		~GameEngine();

		bool isRunning() const;
		void listenEventScene(
			std::shared_ptr<scene::IEventScene> scene);

		void refresh() override;

		irr::gui::IGUIEnvironment *getGui() override;
		irr::video::ITexture *loadTexture(
			const std::string &path) override;
		std::unique_ptr<AudioFile> loadAudioFile(
			const std::string &path) override;
		std::unique_ptr<bomb::AnimatedObject> createAnimatedObject(
			const std::string &path,
			irr::core::vector3df pos,
			irr::core::vector3df rot,
			irr::core::vector3df scale) override;
		std::unique_ptr<bomb::StaticObject> createStaticObject(
			const std::string &path,
			irr::core::vector3df pos,
			irr::core::vector3df rot,
			irr::core::vector3df scale) override;
		std::unique_ptr<menu::Menu> createMenu() override;
		void deleteObject(std::unique_ptr<IObject> obj) override;
		irr::scene::ICameraSceneNode *addCamera(
			const irr::core::vector3df &pos,
			       const irr::core::vector3df &rot) override;
	private:
		EventHandler _evtHandler;
		irr::IrrlichtDevice *_device;
		irr::video::IVideoDriver *_videoDriver;
		irr::scene::ISceneManager *_sceneManager;
		irr::scene::ICameraSceneNode *_camera;
		std::unique_ptr<AudioDevice> _audioDev;
		std::string _path;
	};
}
#endif /* CPP_INDIE_STUDIO_GAMEENGINE_HPP */
