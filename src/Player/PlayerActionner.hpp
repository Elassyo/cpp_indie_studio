//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// PlayerActionner.hpp
//

#ifndef CPP_INDIE_STUDIO_PLAYERACTIONNER_HPP
#define CPP_INDIE_STUDIO_PLAYERACTIONNER_HPP

#include "../Map/Map.hpp"
#include "../Interface/IPlayerController.hpp"

namespace bomb {
	class PlayerActionner {
	public:
		void actionnate(bomb::Map &map,
			std::unique_ptr<bomb::AnimatedObject> &obj,
			IPlayerController::Actions action);
		void setSpeedRatio(float speedRatio);
	private:
		float _speedRatio;
		IPlayerController::Actions _currentAction;
		IPlayerController::Actions _nextAction;
		irr::core::vector3df _target;
	};
}
#endif /* CPP_INDIE_STUDIO_PLAYERACTIONNER_HPP */