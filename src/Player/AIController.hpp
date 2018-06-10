//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// AIController.hpp
//

#ifndef CPP_INDIE_STUDIO_AICONTROLLER_HPP
	#define CPP_INDIE_STUDIO_AICONTROLLER_HPP

	#include <array>
	
	#include "PlayerActionner.hpp"

namespace bomb {
	namespace ai {
		class AIController {
		public:
			AIController();
			void executeAI(PlayerActionner &actionner,
				       std::array<game::Player, 4> &players,
				       BomberMap &map, int index);
			void executeDefensiveAI(PlayerActionner &actionner,
				       std::array<game::Player, 4> &players,
				       BomberMap &map, int index);
			void executeOffensiveAI(PlayerActionner &actionner,
				       std::array<game::Player, 4> &players,
				       BomberMap &map, int index);
		private:
			std::unordered_map<bomb::IPlayerController::Actions,
				irr::core::vector3df> _moves;
		};
	}
}

#endif /* CPP_INDIE_STUDIO_AICONTROLLER_HPP */
