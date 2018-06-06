//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// APlayerController.hpp
//

#ifndef CPP_INDIE_STUDIO_APLAYERCONTROLLER_HPP
#define CPP_INDIE_STUDIO_APLAYERCONTROLLER_HPP

#include "../Map/Map.hpp"

namespace bomb {
	class APlayerController {
	public:
		enum Action {
			TOP,
			LEFT,
			RIGHT,
			BOTTOM,
			BOMB
		};
		Action getCurrentAction();

	protected:
		Action _currentAction;
	};
}

#endif /* CPP_INDIE_STUDIO_APLAYERCONTROLLER_HPP */