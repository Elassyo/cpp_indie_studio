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
			void executeAI(
				PlayerActionner &actionner,
				std::array<game::Player, 4> &players,
				BomberMap &map, int index);
			void executeDefensiveAI(
				PlayerActionner &actionner,
				std::array<game::Player, 4> &players,
				BomberMap &map, int index);
			void executeOffensiveAI(
				PlayerActionner &actionner,
				std::array<game::Player, 4> &players,
				BomberMap &map, int index);
			void executerRandomAI(
				PlayerActionner &actionner,
				std::array<game::Player, 4> &players,
				BomberMap &map, int index);
		private:
			std::map<bomb::IPlayerController::Actions,
				irr::core::vector3df> _moves;
			IPlayerController::Actions vecToDir(
				irr::core::vector3d<irr::f32> vector3d);
			IPlayerController::Actions searchSaferBlock(
				BomberMap &map, Map &safeMap,
				irr::core::vector2di vector2d);
			IPlayerController::Actions searchSaferBlock(
				BomberMap &map, Map safeMap,
				std::map<irr::core::vector2di,
					IPlayerController::Actions> poses);
			irr::core::vector3d<irr::f32> getNextCell(
				irr::core::vector3df &pos,
				IPlayerController::Actions &action);
			irr::core::vector3d<irr::f32> getNextCell(
				std::array<game::Player, 4> &players, int index,
				IPlayerController::Actions &action);
			std::array<std::pair<unsigned int, float>, 4>
			getEnenemyDistances(
				std::array<game::Player, 4> &players,
				int index);
			std::array<std::pair<unsigned int, IPlayerController::Actions>, 4>
			getEnenemyDirections(std::array<game::Player, 4>
						&players, int index);

			bool
	isValidBombPlace(std::array<game::Player, 4> &array, BomberMap &map, int index);
		};
	}
}

#endif /* CPP_INDIE_STUDIO_AICONTROLLER_HPP */
