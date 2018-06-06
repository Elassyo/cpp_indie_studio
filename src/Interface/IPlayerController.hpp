//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// IPlayerController.hpp
//

#ifndef CPP_INDIE_STUDIO_IPLAYERCONTROLLER_HPP
#define CPP_INDIE_STUDIO_IPLAYERCONTROLLER_HPP

#include "../Player/MovementAnalyser.hpp"

namespace bomb {
	class IPlayerController {
	public:
		virtual ~IPlayerController() = default;

		virtual void launch() = 0;
		virtual const MovementAnalyser &requestMovement() const  = 0;
	};
}

#endif /* CPP_INDIE_STUDIO_IPLAYERCONTROLLER_HPP */