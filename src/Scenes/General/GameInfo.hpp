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
#include "Player.hpp"
#include "../../AnimatedObject.hpp"
#include "../../Interface/IAssetLoader.hpp"
#include "../../Map/MapGenerator.hpp"
#include "../../Map/Map.hpp"

#define MAP_SIZE 15

namespace bomb {
	namespace game {
		constexpr int NB_PLAYERS = 4;

		class GameInfo {
		public:
			GameInfo() = default;

			void createGame(
				IAssetLoader &loader,
				irr::video::ITexture *pTexture
			);
			int getMapSize() const;

			void executePlayers();

		private:
			enum Character {
				SHYGUY_WHITE,
				SHYGUY_BLACK,
				SHYGUY_RED,
				SHYGUY_BLUE,
				SKELEREX
			};

			void createMap(
				IAssetLoader &loader,
				unsigned int size
			);
			void createPlayer(bomb::IAssetLoader &loader,
				const std::string &path,
				std::unique_ptr<IPlayerController> controller,
				Character index,
				const irr::core::vector3di &spawn
			);

			void reset();

			std::vector<Player> _players;
			std::shared_ptr<bomb::Map> _map;
			int _mapSize;
		};
	}
}

#endif /* CPP_INDIE_STUDIO_GAMEINFO_HPP */
