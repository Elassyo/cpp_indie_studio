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
			std::map<bomb::IPlayerController::Actions,
				irr::core::vector3df> _moves;
			unsigned int getClosestEnenemy(
				std::array<game::Player, 4> &array, int index);
			IPlayerController::Actions vecToDir(
				irr::core::vector3d<irr::f32> vector3d);
			std::map<irr::core::vector2di,
				IPlayerController::Actions>
			searchSaferBlock(
				BomberMap &map, Map safeMap,
				std::map<irr::core::vector2di,
					IPlayerController::Actions> poses,
				IPlayerController::Actions &action);
			IPlayerController::Actions searchSaferBlock(
				BomberMap &map, Map &safeMap,
				irr::core::vector2di vector2d);
		};
	}
}

#endif /* CPP_INDIE_STUDIO_AICONTROLLER_HPP */
