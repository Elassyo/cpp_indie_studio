/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
** GameInfo.hpp
*/

#ifndef CPP_INDIE_STUDIO_GAMEINFO_HPP
	#define CPP_INDIE_STUDIO_GAMEINFO_HPP

	#include <array>
	#include <map>
	#include <vector>
	#include "../../Interface/IAssetLoader.hpp"
	#include "../../AnimatedObject.hpp"
	#include "PlayerInfo.hpp"
	#include "../../AnimatedObject.hpp"
	#include "../../Interface/IAssetLoader.hpp"
	#include "../../Map/MapGenerator.hpp"
	#include "../../Map/Map.hpp"

namespace bomb {
	namespace game {
		constexpr int NB_PLAYERS = 4;

		class GameInfo {
		public:
			GameInfo() = default;
			void createMap(IAssetLoader &loader,
				irr::video::ITexture *pTexture);
			int getMapSize() const;
		private:
			enum Character {
				SHYGUY_WHITE,
				SHYGUY_BLACK,
				SHYGUY_RED,
				SHYGUY_BLUE,
				SKELEREX
			};

			void reset();

			std::map<Character, std::unique_ptr<AnimatedObject>>
				_characters;
			std::array<PlayerInfo, NB_PLAYERS> _players;

			std::unique_ptr<bomb::Map> _map;
			int _mapSize;
		};
	}
}

#endif /* CPP_INDIE_STUDIO_GAMEINFO_HPP */
