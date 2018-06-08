/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
** Game.hpp
*/

#ifndef CPP_INDIE_STUDIO_GAMEINFO_HPP
#define CPP_INDIE_STUDIO_GAMEINFO_HPP

#include <array>
#include <map>
#include <vector>
#include "../../Interface/IAssetLoader.hpp"
#include "../../AnimatedObject.hpp"
#include "../../AnimatedObject.hpp"
#include "../../Interface/IAssetLoader.hpp"
#include "../../Map/MapGenerator.hpp"
#include "../../Map/Map.hpp"
#include "../../Player/PlayerActionner.hpp"
#include "../SceneGame/Bomb.hpp"
#include "Player.hpp"

#define MAP_SIZE 16

namespace bomb {
	namespace game {
		constexpr int NB_PLAYERS = 4;

		class Game {
		public:
			Game() = default;

			void createGame(
				IAssetLoader &loader,
				irr::video::ITexture *pTexture
			);
			int getMapSize() const;
			void execute(IAssetLoader &loader);
			bool handleEvent(const irr::SEvent &event);

			std::vector<std::pair<Player, PlayerActionner>>
				&getPlayers();
			std::shared_ptr<Map> &getMap();

		private:
			void createMap(
				IAssetLoader &loader,
				unsigned int size
			);
			void createPlayer(bomb::IAssetLoader &loader,
				const std::string &path,
				std::unique_ptr<IPlayerController> controller,
				const irr::core::vector3di &spawn
			);

			void reset();

			std::vector<std::pair<Player, PlayerActionner>>
				_players;
			std::shared_ptr<bomb::Map> _map;
			std::vector<std::unique_ptr<bomb::object::Bomb>> _bombs;
			int _mapSize;
		};
	}
}

#endif /* CPP_INDIE_STUDIO_GAMEINFO_HPP */
