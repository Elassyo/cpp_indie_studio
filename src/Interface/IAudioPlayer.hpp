/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
** IAudioPlayer.hpp
*/

#ifndef CPP_INDIE_STUDIO_IAUDIOPLAYER_HPP
	#define CPP_INDIE_STUDIO_IAUDIOPLAYER_HPP

	#include "IObject.hpp"


namespace bomb {
	class IAudioPlayer {
	public:
		virtual ~IAudioPlayer() = default;

		virtual void playSound
			(const std::string &path, const IObject &obj) = 0;
	};
}

#endif /* CPP_INDIE_STUDIO_IAUDIOPLAYER_HPP */