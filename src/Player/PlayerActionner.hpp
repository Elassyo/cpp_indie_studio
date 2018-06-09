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
#include "../Scenes/General/Clock.hpp"
#include "../Scenes/General/Player.hpp"

namespace bomb {
	class PlayerActionner {
	public:
		PlayerActionner(bool enableRepeat);

		void actionnate(Map &map, bomb::game::Player &player);
		void
		sendAction(Map &map, game::Player &player,
			IPlayerController::Actions action);
		void setSpeedRatio(float speedRatio);

		void removeAction(IPlayerController::Actions actions);

	private:
		std::unordered_map<bomb::IPlayerController::Actions,
			irr::core::vector3df> _moves;
		IPlayerController::Actions _currentAction;
		IPlayerController::Actions _nextAction;
		irr::core::vector3di _target;
		float _speedRatio;
		bool _repeatActionMode;
		bool _repeat;
		bomb::utils::Clock _latence;

		void move(Map &map, game::Player &player);
		irr::core::vector3di vecfCast(irr::core::vector3df &vec);
		bool isTargetReached(irr::core::vector3d<irr::f32> &vector3d);
		irr::core::vector3df veciCast(irr::core::vector3di &vec);
		void updateAction();
		void addBomb(Map &map, game::Player &player);
		void changeTargetTile(Map &map, irr::core::vector3di playerPos,
			      game::Player &player);
	};
}
#endif /* CPP_INDIE_STUDIO_PLAYERACTIONNER_HPP */