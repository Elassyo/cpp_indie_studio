//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// PlayerInfo.hpp
//

#ifndef CPP_INDIE_STUDIO_PLAYERINFO_HPP
#define CPP_INDIE_STUDIO_PLAYERINFO_HPP

#include <cstdint>

namespace bomb {
	namespace game {
		class PlayerInfo {
		public:
			PlayerInfo();

			uint8_t getNbBombs() const;
			void setNbBombs(uint8_t _nbBombs);
			uint8_t getSpeed() const;
			void setSpeed(uint8_t _speed);
			uint8_t getBombRange() const;
			void setBombRange(uint8_t _bombRange);
			bool isGhostMode() const;
			void setGhostMode(bool _ghostMode);
			bool isAlive() const;
			void setAlive(bool _alive);
			uint8_t getCharacterIndex() const;
			void setCharacterIndex(uint8_t _characterIndex);
		private:
			uint8_t _nbBombs;
			uint8_t _speed;
			uint8_t _bombRange;
			bool _ghostMode;
			bool _alive;
			uint8_t _characterIndex;
		};
	}
}
#endif /* CPP_INDIE_STUDIO_PLAYERINFO_HPP */