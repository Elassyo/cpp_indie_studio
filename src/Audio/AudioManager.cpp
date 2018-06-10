/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
** AudioManager.cpp
*/

#include "../Exception/Exception.hpp"
#include "AudioManager.hpp"

bomb::AudioManager::AudioManager(const std::string &assetsPath) :
	_assetsPath(assetsPath)
{
	_device = alcOpenDevice(nullptr);
	if (!_device)
		throw Exception("AudioManager", "Failed to open audio device");
	_context = alcCreateContext(_device, nullptr);
	if (!_context)
		throw Exception("AudioManager",
			"Failed to create OpenAL context");
	alcMakeContextCurrent(_context);
}

bomb::AudioManager::~AudioManager()
{
	for (auto &_audioBuffer : _audioBuffers)
		delete _audioBuffer.second;
	alDeleteSources(_audioSources.size(), _audioSources.data());
	alcMakeContextCurrent(nullptr);
	alcDestroyContext(_context);
	alcCloseDevice(_device);
}

void bomb::AudioManager::loadAudioFile(const std::string &path)
{
	if (_audioBuffers.find(path) != _audioBuffers.end())
		return;
	_audioBuffers[path] = new AudioBuffer(_assetsPath + path);
}

void bomb::AudioManager::unloadAudioFile(const std::string &path)
{
	auto it = _audioBuffers.find(path);
	if (it == _audioBuffers.end())
		return;
	delete it->second;
	_audioBuffers.erase(it);
}

void bomb::AudioManager::updateListener(irr::scene::ICameraSceneNode *camera)
{
	const irr::core::vector3df &pos = camera->getPosition();
	const irr::core::vector3df &target = camera->getTarget();
	irr::core::vector3df at = pos - target;
	const irr::core::vector3df &up = camera->getUpVector();
	ALfloat orientation[] = { at.X, at.Y, at.Z, up.X, up.Y, up.Z };
	alListener3f(AL_POSITION, pos.X / 20, pos.Y / 20, pos.Z / 20);
	alListenerfv(AL_ORIENTATION, orientation);
}

void bomb::AudioManager::playMusic(const std::string &path)
{
	std::vector<ALuint> buffers = getAudioBuffers(path);
	ALuint source = getAudioSource();
	alSourcef(source, AL_GAIN, 0.4f);
	alSourceQueueBuffers(source, buffers.size(), buffers.data());
	alSourcePlay(source);
}

void bomb::AudioManager::playSound(const std::string &path,
	bomb::IObject const &obj)
{
	std::vector<ALuint> buffers = getAudioBuffers(path);
	ALuint source = getAudioSource();
	irr::core::vector3d pos = obj.getPos();
	alSource3f(source, AL_POSITION, pos.X / 20, pos.Y / 20, pos.Z / 20);
	alSourcef(source, AL_GAIN, 1.0f);
	alSourceQueueBuffers(source, buffers.size(), buffers.data());
	alSourcePlay(source);
}

float bomb::AudioManager::getVolume() const
{
	float gain;
	alGetListenerf(AL_GAIN, &gain);
	return gain;
}

void bomb::AudioManager::setVolume(float gain)
{
	alListenerf(AL_GAIN, gain);
}

std::vector<ALuint> bomb::AudioManager::getAudioBuffers(const std::string &path)
{
	auto it = _audioBuffers.find(path);
	if (it == _audioBuffers.end())
		throw Exception("AudioManager",
			"Unknown audio file '" + path + "'");
	return it->second->getBuffers();
}

ALuint bomb::AudioManager::getAudioSource()
{
	for (ALuint source : _audioSources) {
		ALint state;
		alGetSourcei(source, AL_SOURCE_STATE, &state);
		if (state == AL_STOPPED) {
			alSourcei(source, AL_BUFFER, AL_NONE);
			return source;
		}
	}
	ALuint source;
	alGenSources(1, &source);
	_audioSources.push_back(source);
	return source;
}

void bomb::AudioManager::pauseAll()
{
	for (ALuint source : _audioSources) {
		ALint state;
		alGetSourcei(source, AL_SOURCE_STATE, &state);
		if (state == AL_PLAYING)
			alSourcePause(source);
	}
}

void bomb::AudioManager::resumeAll()
{
	for (ALuint source : _audioSources) {
		ALint state;
		alGetSourcei(source, AL_SOURCE_STATE, &state);
		if (state == AL_PAUSED)
			alSourcePlay(source);
	}
}

void bomb::AudioManager::stopAll()
{
	for (ALuint source : _audioSources) {
		ALint state;
		alGetSourcei(source, AL_SOURCE_STATE, &state);
		alSourceStop(source);
	}
}
