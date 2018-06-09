//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// Player.hpp
//

#ifndef CPP_INDIE_STUDIO_PLAYER_HPP
#define CPP_INDIE_STUDIO_PLAYER_HPP

#include <unordered_map>
#include "../../AnimatedObject.hpp"
#include "../../Interface/IAssetManager.hpp"
#include "../../Interface/IPlayerController.hpp"
#include "../../Map/Map.hpp"
#include "PlayerInfo.hpp"

namespace bomb {
	namespace game {
		class Player {
		public:
			Player(bomb::IAssetManager &loader,
				const std::string &path,
				std::unique_ptr<bomb::IPlayerController> &ctrl,
				const irr::core::vector3df &pos,
				const irr::core::vector3df &scale,
			       	const irr::core::vector3df &rotation,
				bomb::PlayerInfo &info);

			IPlayerController::Actions
			getActionFromEvent(const irr::SEvent &event);
			void execute(Map &map);

			uint8_t getNbBombs() const;
			float getSpeed() const;
			uint8_t getBombRange() const;
			bool isGhostMode() const;
			bool isGhostBombMode() const;
			bool isAlive() const;
			bool isAI() const;
			void setBombReady(bool);
			irr::core::vector3df getExactPos() const;

			void setNbBombs(uint8_t _nbBombs);
			void setSpeed(float _speed);
			void setBombRange(uint8_t _bombRange);
			void setGhostMode(bool _ghostMode);
			void setGhostBombMode(bool _ghostBombMode);
			void setAlive(bool _alive, IAssetManager &loader);
			void setAI(bool AI);
			bool isBombReady();

			std::unique_ptr<AnimatedObject> &getModel();
		private:
			uint8_t _maxNbBombs;
			uint8_t _nbBombs;
			float _speed;
			uint8_t _bombRange;
			bool _ghostMode;
			bool _ghostBombMode;
			bool _alive;
			bool _AI;
			bool _bombReady;

			std::unique_ptr<AnimatedObject> _model;
			std::unique_ptr<IPlayerController> _controller;
			bomb::PlayerInfo _genericInfos;
		};
	}
}
#endif /* CPP_INDIE_STUDIO_PLAYER_HPP */