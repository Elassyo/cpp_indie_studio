//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// PlayerActionner.hpp
//

#ifndef CPP_INDIE_STUDIO_PLAYERACTIONNER_HPP
#define CPP_INDIE_STUDIO_PLAYERACTIONNER_HPP

#include <unordered_map>
#include "../Map/Map.hpp"
#include "../Interface/IPlayerController.hpp"

namespace bomb {
	class PlayerActionner {
	public:
		PlayerActionner();

		void sendAction(bomb::Map &map,
			std::unique_ptr<bomb::AnimatedObject> &obj,
			IPlayerController::Actions action);
		void actionnate(bomb::Map &map,
			std::unique_ptr<bomb::AnimatedObject> &obj);
		void setSpeedRatio(float speedRatio);
	private:
		void addBomb(Map &map, std::unique_ptr<AnimatedObject> &player);
		std::unordered_map<bomb::IPlayerController::Actions,
			irr::core::vector3df> _moves;
		float _speedRatio;
		IPlayerController::Actions _currentAction;
		IPlayerController::Actions _nextAction;
		irr::core::vector3di _target;

		void move(Map &map, std::unique_ptr<AnimatedObject> &player);
		void changeTargetTile(Map &map,
			std::unique_ptr<AnimatedObject> &player);
		irr::core::vector3di vecfCast(irr::core::vector3df &vec);
		bool isTargetReached(irr::core::vector3d<irr::f32> &vector3d);

		irr::core::vector3df veciCast(irr::core::vector3di &vec);
	};
}
#endif /* CPP_INDIE_STUDIO_PLAYERACTIONNER_HPP */