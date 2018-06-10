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
	#include "../Interface/IAudioListener.hpp"
	#include "../Interface/IAudioPlayer.hpp"

namespace bomb {

	class AudioManager :
		public virtual IAudioListener,
		public virtual IAudioPlayer {
	public:
		explicit AudioManager(const std::string &assetsPath);
		AudioManager(const AudioManager &other) = delete;
		~AudioManager();

		AudioManager &operator=(const AudioManager &other) = delete;

		void loadAudioFile(const std::string &path);
		void unloadAudioFile(const std::string &path);

		void updateListener(irr::scene::ICameraSceneNode *camera);

		void playMusic(const std::string &path);
		void playSound(const std::string &path, const IObject &obj) override;

		void pauseAll();
		void resumeAll();
		void stopAll();

		float getVolume() const;
		void setVolume(float gain);

	private:
		std::vector<ALuint> getAudioBuffers(const std::string &path);
		ALuint getAudioSource();

		std::string _assetsPath;

		ALCdevice *_device;
		ALCcontext *_context;

		std::map<std::string,AudioBuffer*> _audioBuffers;
		std::vector<ALuint> _audioSources;
	};

}

#endif /* CPP_INDIE_STUDIO_AUDIODEVICE_HPP */
