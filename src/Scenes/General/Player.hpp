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
#include "../../Player/PlayerActionner.hpp"

namespace bomb {
	namespace game {
		class Player {
		public:
			Player(bomb::IAssetLoader &loader,
				const std::string &path,
				std::unique_ptr<bomb::IPlayerController> &ctrl,
				const irr::core::vector3df &pos,
				const irr::core::vector3df &scale,
			       	const irr::core::vector3df &rotation);

			bool handleEvent(Map &map, const irr::SEvent &event);
			void execute(Map &map);

			uint8_t getNbBombs() const;
			float getSpeed() const;
			uint8_t getBombRange() const;
			bool isGhostMode() const;
			bool isAlive() const;
			bool isAI() const;

			void setNbBombs(uint8_t _nbBombs);
			void setSpeed(float _speed);
			void setBombRange(uint8_t _bombRange);
			void setGhostMode(bool _ghostMode);
			void setAlive(bool _alive);
			void setAI(bool AI);

		private:
			PlayerActionner _actionner;
			uint8_t _nbBombs;
			float _speed;
			uint8_t _bombRange;
			bool _ghostMode;
			bool _alive;
			bool _AI;
			std::unordered_map<irr::EKEY_CODE,
				std::pair<bomb::IPlayerController::Actions,
					wchar_t *>> _keys;

			std::unique_ptr<AnimatedObject> _obj;
			std::unique_ptr<IPlayerController> _controller;
		};
	}
}
#endif /* CPP_INDIE_STUDIO_PLAYERINFO_HPP */