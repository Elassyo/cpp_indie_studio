/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
** AudioManager.cpp
*/

#include "../Exception/Exception.hpp"
#include "AudioManager.hpp"

bomb::AudioManager::AudioManager()
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
	alcMakeContextCurrent(nullptr);
	alcDestroyContext(_context);
	alcCloseDevice(_device);
}

void bomb::AudioManager::loadAudioFile(const std::string &path)
{
	if (_audioBuffers.find(path) != _audioBuffers.end())
		return;
	_audioBuffers[path] = (new AudioBuffer(path));
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
	alListener3f(AL_POSITION, pos.X, pos.Y, pos.Z);
	alListenerfv(AL_ORIENTATION, orientation);
}

void bomb::AudioManager::playMusic(const std::string &path)
{
	ALuint buffer = getAudioBuffer(path);
	ALuint source = getAudioSource();
	alSourcei(source, AL_LOOPING, AL_TRUE);
	alSourcei(source, AL_BUFFER, buffer);
	alSourcePlay(source);
}

void bomb::AudioManager::playSound(const std::string &path,
	bomb::AObject const &obj)
{
	ALuint buffer = getAudioBuffer(path);
	ALuint source = getAudioSource();
	irr::core::vector3d pos = obj.getPos();
	alSource3f(source, AL_POSITION, pos.X, pos.Y, pos.Z);
	alSourcei(source, AL_LOOPING, AL_FALSE);
	alSourcei(source, AL_BUFFER, buffer);
	alSourcePlay(source);
}

void bomb::AudioManager::setVolume(float gain)
{
	alListenerf(AL_GAIN, gain);
}

ALuint bomb::AudioManager::getAudioBuffer(const std::string &path)
{
	auto it = _audioBuffers.find(path);
	if (it == _audioBuffers.end())
		throw Exception("AudioManager",
			"Unknown audio file '" + path + "'");
	return it->second->getBuffer();
}

ALuint bomb::AudioManager::getAudioSource()
{
	for (ALuint source : _audioSources) {
		ALint state;
		alGetSourcei(source, AL_SOURCE_STATE, &state);
		if (state == AL_STOPPED)
			return source;
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