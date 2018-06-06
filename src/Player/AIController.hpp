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
			AIController();
			void launch() override;

		private:
			void moveRandom();
			utils::Clock _clock;
		};
	}
}

#endif /* CPP_INDIE_STUDIO_AICONTROLLER_HPP */