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
	#include "Player.hpp"
	#include "../../AnimatedObject.hpp"
	#include "../../Interface/IAssetLoader.hpp"
	#include "../../Map/MapGenerator.hpp"
	#include "../../Map/Map.hpp"
	#include "../../Player/PlayerActionner.hpp"
	#include "../../Xml/XmlWriter.hpp"
	#include "../SceneGame/Bomb.hpp"
	#include "PersistentInfo.hpp"
	#include "../../Exception/Exception.hpp"
	#include "../../Player/AIController.hpp"


#define MAP_SIZE 15

namespace bomb {
	namespace game {
		constexpr int NB_PLAYERS = 4;

		class Game {
		public:
			Game(PersistentInfo &_infos);

			void createGame(
				IAssetLoader &loader,
				irr::video::ITexture *pTexture
			);
			int getMapSize() const;
			void execute(IAssetLoader &loader);
			bool handleEvent(const irr::SEvent &event);
			std::shared_ptr<Map> &getMap();

			std::vector<std::pair<Player, PlayerActionner>>
				&getPlayers();

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

			PersistentInfo &_infos;
			bomb::game::CharacterLoader _charLoader;
			std::vector<std::pair<Player, PlayerActionner>>
				_players;
			std::shared_ptr<bomb::Map> _map;
			std::vector<bomb::object::Bomb *> _bombs;
			int _mapSize;

			void killPlayersInBlast(
				std::vector<irr::core::vector2di> &vector,
				bomb::IAssetLoader &loader);
			void executePlayers(IAssetLoader &loader);
			void executeBombs(IAssetLoader &loader);
		};
	}
}

#endif /* CPP_INDIE_STUDIO_GAMEINFO_HPP */