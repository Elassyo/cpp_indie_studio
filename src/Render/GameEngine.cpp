//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// GameEngine.cpp
//

#include <memory>

#include "../Exception/Exception.hpp"
#include "../Menu/Menu.hpp"
#include "GameEngine.hpp"

bomb::GameEngine::GameEngine(const std::wstring &winName,
	unsigned int w, unsigned int h,
	irr::video::E_DRIVER_TYPE driver_type) :
	_device(irr::createDevice(driver_type, irr::core::dimension2d(w, h), 16,
		false, false, false, &_evtHandler)),
	_videoDriver(_device->getVideoDriver()),
	_sceneManager(_device->getSceneManager()),
	_camera(nullptr),
	_audioDev(new AudioDevice()),
	_assetsPath(Version::GetCurrentVersion().getAssetsPath())
{
	_device->setWindowCaption(winName.c_str());
}

bomb::GameEngine::~GameEngine()
{
	_device->drop();
}

bool bomb::GameEngine::isRunning() const
{
	return _device->run();
}

void bomb::GameEngine::listenEventScene(
	std::shared_ptr<bomb::scene::IEventScene> scene)
{
	_evtHandler.injectScene(scene);
}

void bomb::GameEngine::refresh()
{
	_videoDriver->beginScene(true, true, irr::video::SColor(255,44,62,80));
	_sceneManager->drawAll();
	getGui()->drawAll();
	_videoDriver->endScene();
}

irr::gui::IGUIEnvironment *bomb::GameEngine::getGui()
{
	return _device->getGUIEnvironment();
}

irr::video::ITexture *bomb::GameEngine::loadTexture(const std::string &path)
{

	return _videoDriver->getTexture((_assetsPath + path).c_str());
}

std::unique_ptr<bomb::AudioFile> bomb::GameEngine::loadAudioFile(
	const std::string &path)
{
	return std::make_unique<AudioFile>(path);
}

std::unique_ptr<bomb::AnimatedObject> bomb::GameEngine::createAnimatedObject(
	const std::string &path,
	irr::core::vector3df pos,
	irr::core::vector3df scale,
	irr::core::vector3df rot)
{
	auto ptr = std::make_unique<bomb::AnimatedObject>(
		_sceneManager->addAnimatedMeshSceneNode(
			_sceneManager->getMesh((_assetsPath + path).c_str())));
	ptr->setPos(pos);
	ptr->setRot(rot);
	ptr->setScale(scale);
	return ptr;
}

std::unique_ptr<bomb::StaticObject> bomb::GameEngine::createStaticObject(
	const std::string &path,
	irr::core::vector3df pos,
	irr::core::vector3df scale,
	irr::core::vector3df rot)
{
	auto ptr = std::make_unique<bomb::StaticObject>(
		_sceneManager->addMeshSceneNode(_sceneManager->getMesh(
			(_assetsPath + path).c_str())));
	ptr->setPos(pos);
	ptr->setRot(rot);
	ptr->setScale(scale);
	return ptr;
}

std::unique_ptr<bomb::menu::Menu> bomb::GameEngine::createMenu()
{
	return std::make_unique<bomb::menu::Menu>(_videoDriver, getGui());
}

void bomb::GameEngine::deleteObject(std::unique_ptr<bomb::IObject> obj)
{
	_sceneManager->addToDeletionQueue(obj->getSceneNode());
}

irr::scene::ICameraSceneNode *bomb::GameEngine::addCamera(
	const irr::core::vector3df &pos,
	const irr::core::vector3df &rot)
{
	if (_camera)
		throw Exception("GameEngine", "Camera already created");
	_camera = _sceneManager->addCameraSceneNode();
	if (!_camera)
		throw Exception("GameEngine", "Can't create camera");
	_camera->setPosition(pos);
	_camera->setTarget(rot);
	return _camera;
}
