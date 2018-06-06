/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
** AudioManager.hpp
*/

#ifndef CPP_INDIE_STUDIO_AUDIODEVICE_HPP
	#define CPP_INDIE_STUDIO_AUDIODEVICE_HPP

	#include <map>
	#include <vector>
	#include <AL/al.h>
	#include <AL/alc.h>

	#include "AudioBuffer.hpp"
	#include "../AObject.hpp"

namespace bomb {

	class AudioManager {
	public:
		AudioManager();
		AudioManager(const AudioManager &other) = delete;
		~AudioManager();

		AudioManager &operator=(const AudioManager &other) = delete;

		void loadAudioFile(const std::string &path);
		void unloadAudioFile(const std::string &path);

		void updateListener(irr::scene::ICameraSceneNode *camera);

		void playMusic(const std::string &path);
		void playSound(const std::string &path, const AObject &obj);

		void pauseAll();
		void resumeAll();
		void stopAll();

		void setVolume(float gain);

	private:
		ALuint getAudioBuffer(const std::string &path);
		ALuint getAudioSource();

		ALCdevice *_device;
		ALCcontext *_context;

		std::map<std::string,AudioBuffer*> _audioBuffers;
		std::vector<ALuint> _audioSources;
	};

}

#endif /* CPP_INDIE_STUDIO_AUDIODEVICE_HPP */
