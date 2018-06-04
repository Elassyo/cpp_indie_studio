/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
** AudioDevice.hpp
*/

#ifndef CPP_INDIE_STUDIO_AUDIODEVICE_HPP
	#define CPP_INDIE_STUDIO_AUDIODEVICE_HPP

	#include <AL/al.h>
	#include <AL/alc.h>

namespace bomb {

	class AudioDevice {
	public:
		AudioDevice();
		~AudioDevice();

		// Make objects non copyable
		AudioDevice(const AudioDevice &other) = delete;
		AudioDevice &operator=(const AudioDevice &other) = delete;

	private:
		ALCdevice *_device;
		ALCcontext *_context;
	};

}

#endif /* CPP_INDIE_STUDIO_AUDIODEVICE_HPP */
