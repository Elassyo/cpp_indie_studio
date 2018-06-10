//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// AIController.hpp
//

#ifndef CPP_INDIE_STUDIO_AICONTROLLER_HPP
#define CPP_INDIE_STUDIO_AICONTROLLER_HPP

#include "APlayerController.hpp"
#include "../Scenes/General/Clock.hpp"

#define AI_INTERVAL 1000

namespace bomb {
	namespace player {
		class AIController : public APlayerController {
		public:
			AIController(const std::shared_ptr<bomb::BomberMap> &);
			void execute(const irr::core::vector2di &pos) override;

		private:
			Actions astar(const irr::core::vector2di &from, const irr::core::vector2di &to);
			bomb::IPlayerController::Actions execAstar(std::vector<irr::core::vector2di> path,
				const irr::core::vector2di &last, const irr::core::vector2di &dest);

			void accessBlock(const irr::core::vector2di &from);
			void checkBorder(const irr::core::vector2di &from);

			bool isAccessible(const irr::core::vector2di &to);

			void initQuest();

			bool isSafe(const irr::core::vector2di &pos);
			bool isWalkable(const irr::core::vector2di &pos);

			irr::core::vector2di _quest;
			bool _haveQuest;

			const std::shared_ptr<bomb::BomberMap> &_map;

			std::vector<irr::core::vector2di> _access;
		};
	}
}

#endif /* CPP_INDIE_STUDIO_AICONTROLLER_HPP */