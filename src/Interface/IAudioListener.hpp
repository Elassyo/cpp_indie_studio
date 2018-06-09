/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
** IAudioListener.hpp
*/

#ifndef CPP_INDIE_STUDIO_IAUDIOLISTENER_HPP
	#define CPP_INDIE_STUDIO_IAUDIOLISTENER_HPP

	#include "irrlicht/irrlicht.h"

namespace bomb {
	class IAudioListener {
	public:
		virtual ~IAudioListener() = default;

		virtual void updateListener
			(irr::scene::ICameraSceneNode *camera) = 0;
	};
}

#endif /* CPP_INDIE_STUDIO_IAUDIOLISTENER_HPP */