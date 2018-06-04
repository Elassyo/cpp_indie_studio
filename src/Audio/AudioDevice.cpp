/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
** AudioDevice.cpp
*/

#include "../Exception/Exception.hpp"
#include "AudioDevice.hpp"

bomb::AudioDevice::AudioDevice()
{
	_device = alcOpenDevice(nullptr);
	if (!_device)
		throw Exception("AudioDevice", "Failed to open audio device");
	_context = alcCreateContext(_device, nullptr);
	if (!_context)
		throw Exception("AudioDevice",
			"Failed to create OpenAL context");
	alcMakeContextCurrent(_context);
}

bomb::AudioDevice::~AudioDevice()
{
	alcMakeContextCurrent(nullptr);
	alcDestroyContext(_context);
	alcCloseDevice(_device);
}
