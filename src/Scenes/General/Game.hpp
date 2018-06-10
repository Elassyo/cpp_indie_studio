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

	#include "../../Interface/IAssetManager.hpp"
	#include "../../AnimatedObject.hpp"
	#include "Player.hpp"
	#include "../../AnimatedObject.hpp"
	#include "../../Interface/IAssetManager.hpp"
	#include "../../Map/MapGenerator.hpp"
	#include "../../Map/Map.hpp"
	#include "../../Player/PlayerActionner.hpp"
	#include "../../Xml/XmlWriter.hpp"
	#include "../SceneGame/Bomb.hpp"
	#include "PersistentInfo.hpp"
	#include "../../Exception/Exception.hpp"
	#include "../../Player/AIController.hpp"
	#include "../SceneGame/Powers/Power.hpp"
	#include "../SceneGame/Powers/PowerFactory.hpp"
	#include "../../Xml/XmlReader.hpp"


namespace bomb {
	namespace game {
		constexpr int NB_PLAYERS = 4;

		class Game {
		public:
			Game(PersistentInfo &_infos);

			void createGame(
				IAssetManager &loader,
				irr::video::ITexture *pTexture
			);
			void createGame(
				IAssetManager &loader,
				irr::video::ITexture *pTexture,
				const std::string &fileName
			);
			int getMapSize() const;
			void execute(IAssetManager &loader);
			bool handleEvent(const irr::SEvent &event);
			std::shared_ptr<Map> &getMap();

			std::vector<std::pair<Player, PlayerActionner>>
				&getPlayers();

		private:
			void createMap(
				IAssetManager &loader,
				unsigned int size
			);
			void createMap(
				IAssetManager &loader,
				xml::XmlReader &
			);

			void createPlayer(
				IAssetLoader &loader,
				const std::string &path,
				std::unique_ptr<IPlayerController> controller,
				const irr::core::vector3di &spawn);
			void killPlayersInBlast(
				irr::core::vector2di blast,
				IAssetManager &loader);
			void killPowersInBlast(
				irr::core::vector2di vector,
				IAssetManager &manager);
			void blastObjects(
				std::vector<std::pair<irr::core::vector2di,
					Map::BlockType>> vector,
				IAssetManager &manager);
			void executePlayers(IAssetManager &loader);
			void executeBombs(IAssetManager &loader);
			void executePowers(IAssetManager &loader);
			void reset();
			void
			spawnPowers(std::vector<std::pair<irr::core::vector2di,
				Map::BlockType>> &blast, IAssetManager &loader);

			PersistentInfo &_infos;
			bomb::game::CharacterLoader _charLoader;
			std::vector<std::pair<Player, PlayerActionner>>
				_players;
			std::shared_ptr<bomb::Map> _map;
			std::vector<bomb::object::Bomb *> _bombs;
			std::vector<std::unique_ptr<bomb::object::Power>>
				_powers;
			std::unordered_map
				<std::wstring, Map::BlockType> _strBlk;
			int _mapSize;
			bomb::object::PowerFactory _factory;
		};
	}
}

#endif /* CPP_INDIE_STUDIO_GAMEINFO_HPP */
