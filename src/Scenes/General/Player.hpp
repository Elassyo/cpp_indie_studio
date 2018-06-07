//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// Player.hpp
//

#ifndef CPP_INDIE_STUDIO_PLAYERINFO_HPP
#define CPP_INDIE_STUDIO_PLAYERINFO_HPP

#include <unordered_map>
#include "../../AnimatedObject.hpp"
#include "../../Interface/IAssetLoader.hpp"
#include "../../Interface/IPlayerController.hpp"

namespace bomb {
	namespace game {
		class Player {
		public:
			Player(bomb::IAssetLoader &loader,
					const std::string &path,
					std::unique_ptr<bomb::IPlayerController> &controller,
					const irr::core::vector3df &pos,
					const irr::core::vector3df &scale,
					const irr::core::vector3df &rotation);

			void startController();
			void closeController();

			uint8_t getNbBombs() const;
			float getSpeed() const;
			uint8_t getBombRange() const;
			bool isGhostMode() const;
			bool isAlive() const;
			uint8_t getCharacterIndex() const;

			void setNbBombs(uint8_t _nbBombs);
			void setSpeed(float _speed);
			void setBombRange(uint8_t _bombRange);
			void setGhostMode(bool _ghostMode);
			void setAlive(bool _alive);
			void setCharacterIndex(uint8_t _characterIndex);

			void execute();

		private:
			const
			std::unordered_map<bomb::IPlayerController::Actions,
				irr::core::vector3df> _moves;
			uint8_t _nbBombs;
			float _speed;
			uint8_t _bombRange;
			bool _ghostMode;
			bool _alive;
			uint8_t _characterIndex;
			IPlayerController::Actions _currentAction;
			IPlayerController::Actions _nextAction;
			irr::core::vector3df _target;

			std::unique_ptr<AnimatedObject> _obj;
			std::unique_ptr<IPlayerController> _controller;
		};
	}
}
#endif /* CPP_INDIE_STUDIO_PLAYERINFO_HPP */