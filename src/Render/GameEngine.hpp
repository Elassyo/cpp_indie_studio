//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// GameEngine.hpp
//

#ifndef CPP_INDIE_STUDIO_GAMEENGINE_HPP
	#define CPP_INDIE_STUDIO_GAMEENGINE_HPP

	#include <memory>
	#include <utility>
	#include <irrlicht/irrlicht.h>
	#include "../Audio/AudioManager.hpp"
	#include "../Interface/IAssetManager.hpp"
	#include "../Interface/IRenderWindow.hpp"
	#include "../AnimatedObject.hpp"
	#include "../CameraObject.hpp"
	#include "../StaticObject.hpp"
	#include "../LightObject.hpp"
	#include "../BillboardObject.hpp"
	#include "../Version.hpp"
	#include "EventHandler.hpp"
	#include "../Exception/Exception.hpp"


namespace bomb {
	class GameEngine :
		virtual public IAssetManager, virtual public IRenderWindow {
	public:
		GameEngine(const std::wstring &winName,
			unsigned int x, unsigned int h,
			irr::video::E_DRIVER_TYPE);
		~GameEngine() override;

		bool isRunning() const;
		void listenEventScene(
			std::shared_ptr<scene::IEventScene> scene);

		void refresh() override;

		irr::gui::IGUIEnvironment *getGui() override;
		irr::video::ITexture *loadTexture(
			const std::string &path) override;
		void loadAudioFile(const std::string &path) override;
		irr::gui::IGUIFont *loadFont(
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
		std::unique_ptr<bomb::LightObject> createLightObject(
			const irr::core::vector3df &pos,
			irr::video::SColorf col, float radius) override;
		std::unique_ptr<PlaneObject> createPlaneObject
			(const std::string &path,
			 irr::core::vector3df pos,
			 irr::core::vector3df rot,
			 irr::core::vector3df scale) override;

		std::unique_ptr<BillboardObject>
		createBillboardObject(irr::core::vector3df pos,
				      irr::core::vector3df rot,
				      irr::core::vector3df scale) override;

		void deleteObject(std::unique_ptr<IObject> obj) override;
		std::unique_ptr<CameraObject> getCamera(
			const irr::core::vector3df &pos,
			const irr::core::vector3df &rot) override;
		const irr::core::dimension2d<irr::u32> &getScreenSize()
			override;

		void unloadAudioFile(const std::string &path) override;
		void playMusic(const std::string &path) override;
		void pauseAll() override;
		void stopAll() override;

	private:
		EventHandler _evtHandler;
		irr::IrrlichtDevice *_device;
		irr::video::IVideoDriver *_videoDriver;
		irr::scene::ISceneManager *_sceneManager;
		irr::scene::ICameraSceneNode *_camera;
		std::string _assetsPath;
		AudioManager _audioMgr;
	};
}
#endif /* CPP_INDIE_STUDIO_GAMEENGINE_HPP */
