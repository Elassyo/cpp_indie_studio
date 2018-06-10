//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// GameEngine.cpp
//

#include "GameEngine.hpp"

bomb::GameEngine::GameEngine(const std::wstring &winName,
			unsigned int w, unsigned int h,
			irr::video::E_DRIVER_TYPE driver_type) :
	_device(irr::createDevice(driver_type, irr::core::dimension2d(w, h), 16,
		false, false, false, &_evtHandler)),
	_videoDriver(_device->getVideoDriver()),
	_sceneManager(_device->getSceneManager()),
	_camera(nullptr),
	_assetsPath(Version::GetCurrentVersion().getAssetsPath()),
	_audioMgr(_assetsPath)
{
	_device->setWindowCaption(winName.c_str());
}

bomb::GameEngine::~GameEngine()
{
	_device->closeDevice();
	_device->run();
	_device->drop();
}

bool bomb::GameEngine::isRunning() const
{
	return _device->run();
}

void bomb::GameEngine::listenEventScene(
	std::shared_ptr<bomb::scene::IEventScene> scene)
{
	_evtHandler.injectScene(std::move(scene));
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

void bomb::GameEngine::loadAudioFile(const std::string &path)
{
	_audioMgr.loadAudioFile(path);
}

void bomb::GameEngine::unloadAudioFile(const std::string &path)
{
	_audioMgr.unloadAudioFile(path);
}

irr::gui::IGUIFont *bomb::GameEngine::loadFont(const std::string &path)
{
	return getGui()->getFont((_assetsPath + path).c_str());
}

std::unique_ptr<bomb::AnimatedObject> bomb::GameEngine::createAnimatedObject(
	const std::string &path,
	irr::core::vector3df pos,
	irr::core::vector3df scale,
	irr::core::vector3df rot)
{
	auto ptr = std::make_unique<bomb::AnimatedObject>(
		_sceneManager->addAnimatedMeshSceneNode(
			_sceneManager->getMesh((_assetsPath + path).c_str())),
	_audioMgr);
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
			(_assetsPath + path).c_str())),
	_audioMgr);
	ptr->setPos(pos);
	ptr->setRot(rot);
	ptr->setScale(scale);
	return ptr;
}

std::unique_ptr<bomb::LightObject> bomb::GameEngine::createLightObject(
	const irr::core::vector3df &pos, irr::video::SColorf col, float radius)
{
	return std::make_unique<bomb::LightObject>(
		_sceneManager->addLightSceneNode(nullptr, pos, col, radius),
		_audioMgr);
}

void bomb::GameEngine::deleteObject(std::unique_ptr<bomb::IObject> obj)
{
	_sceneManager->addToDeletionQueue(obj->getSceneNode());
}

std::unique_ptr<bomb::CameraObject> bomb::GameEngine::getCamera(
	const irr::core::vector3df &pos,
	const irr::core::vector3df &rot)
{
	if (_camera)
		return std::make_unique<CameraObject>(_camera, _audioMgr);
	_camera = _sceneManager->addCameraSceneNode();
	if (!_camera)
		throw Exception("GameEngine", "Can't create camera");
	_camera->setPosition(pos);
	_camera->setRotation(rot);
	return std::make_unique<CameraObject>(_camera, _audioMgr);
}

const irr::core::dimension2d<irr::u32> &bomb::GameEngine::getScreenSize()
{
	return _videoDriver->getScreenSize();
}

std::unique_ptr<bomb::PlaneObject>
bomb::GameEngine::createPlaneObject(const std::string &name,
				    irr::core::vector3df pos,
				    irr::core::vector3df rot,
				    irr::core::vector3df scale)
{
	irr::scene::IAnimatedMesh *imesh = _sceneManager->addHillPlaneMesh
		(irr::io::path(name.c_str()), irr::core::dimension2df(10, 10),
		 irr::core::dimension2d<unsigned int>(10, 10));
	auto node = _sceneManager->addAnimatedMeshSceneNode(imesh);
	auto ptr = std::make_unique<PlaneObject>(node, _audioMgr);
	ptr->setPos(pos);
	ptr->setRot(rot);
	ptr->setScale(scale);
	return ptr;
}

void bomb::GameEngine::playMusic(const std::string &path)
{
	_audioMgr.playMusic(path);
}

void bomb::GameEngine::stopAll()
{
	_audioMgr.stopAll();
}

void bomb::GameEngine::pauseAll()
{
	_audioMgr.pauseAll();
}

std::unique_ptr<bomb::BillboardObject>
bomb::GameEngine::createBillboardObject(irr::core::vector3df pos,
					irr::core::vector3df rot,
					irr::core::vector3df scale)
{
	auto ptr = std::make_unique<bomb::BillboardObject>(
		_sceneManager->addBillboardSceneNode(),
		_audioMgr);
	ptr->setPos(pos);
	ptr->setRot(rot);
	ptr->setScale(scale);
	return ptr;
}

void bomb::GameEngine::setVolume(float gain)
{
	_audioMgr.setVolume(gain);
}
