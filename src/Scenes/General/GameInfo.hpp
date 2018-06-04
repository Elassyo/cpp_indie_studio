/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
** GameInfo.hpp
*/

#ifndef CPP_INDIE_STUDIO_GAMEINFO_HPP
	#define CPP_INDIE_STUDIO_GAMEINFO_HPP

	#define NB_PLAYERS() (4)

	#include <vector>
#include <src/Map/MapGenerator.hpp>
#include "../../AnimatedObject.hpp"
	#include "PlayerInfo.hpp"
	#include "../../Interface/IAssetLoader.hpp"
	#include "../../Map/Map.hpp"

namespace bomb {
	namespace game {
		class GameInfo {
		public:
			GameInfo(IAssetLoader &loader);
		private:
			enum CHARACTERS {
				SHYGUY_WHITE,
				SHYGUY_BLACK,
				SHYGUY_RED,
				SHYGUY_BLUE,
				SKELEREX
			};
			bomb::IAssetLoader &_loader;
			std::vector<std::unique_ptr<AnimatedObject>>
				_characters;
			std::array<PlayerInfo, NB_PLAYERS()> _players;

			bomb::MapGenerator _mapGenerator;
			std::unique_ptr<bomb::Map> _map;

			void reset();
			void createMap(IAssetLoader &loader);

		};
	}
}

#endif /* CPP_INDIE_STUDIO_GAMEINFO_HPP */