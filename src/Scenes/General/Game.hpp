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
	#include "../../Map/BomberMap.hpp"
	#include "../../Player/PlayerActionner.hpp"
	#include "../../Xml/XmlWriter.hpp"
	#include "../SceneGame/Bomb.hpp"
	#include "PersistentInfo.hpp"
	#include "../../Exception/Exception.hpp"
	#include "../../Player/AIController.hpp"
	#include "../SceneGame/Powers/Power.hpp"
	#include "../SceneGame/Powers/PowerFactory.hpp"
	#include "../../Xml/XmlReader.hpp"
	#include "../SceneGame/ExplosionBlast.hpp"


namespace bomb {
	namespace game {
		constexpr int NB_PLAYERS = 4;
		constexpr int RATIO_POWERS = 30;

		class Game {
		public:
			explicit Game(PersistentInfo &_infos);

			void createGame(
				IAssetManager &loader,
				irr::video::ITexture *pTexture
			);
			void createGame(
				IAssetManager &loader,
				irr::video::ITexture *pTexture,
				const std::string &fileName
			);

			void execute(IAssetManager &loader);
			bool handleEvent(const irr::SEvent &event);


			std::shared_ptr<BomberMap> &getMap();
			int getMapSize() const;
			std::array<Player, 4> & getPlayers();
			void clean(IAssetManager &loader);
		private:
			void createMap(
				IAssetManager &loader,
				unsigned int size
			);
			void createMap(
				IAssetManager &loader,
				xml::XmlReader &
			);

			void createPlayer(IAssetLoader &loader,
					  const std::string &path,
					  const irr::core::vector3di &spawn,
					  unsigned int index);
			void killPlayersInBlast(
				irr::core::vector2di blast,
				IAssetManager &loader);
			void killPowersInBlast(
				irr::core::vector2di vector,
				IAssetManager &manager);
			void fuseBombInBlast(irr::core::vector2di pos);
			void blastObjects(
				std::vector<std::pair<irr::core::vector2di,
					BomberMap::BlockType>> vector,
				IAssetManager &manager);
			void executePlayers(IAssetManager &loader);
			void executeBombs(IAssetManager &loader);
			void executePowers(IAssetManager &loader);
			void executeBlast(IAssetManager &manager);
			void reset();
			void
			spawnPowers(std::vector<std::pair<irr::core::vector2di,
				BomberMap::BlockType>> &blast, IAssetManager &loader);

			PersistentInfo &_infos;
			bomb::game::CharacterLoader _charLoader;
			std::array<Player, 4> _players;
			std::array<PlayerActionner, 4> _playersActionners;
			std::shared_ptr<bomb::BomberMap> _map;
			std::vector<bomb::object::Bomb *> _bombs;
			std::vector<std::unique_ptr<bomb::object::Power>>
				_powers;
			bomb::ai::AIController _controller;
			std::unordered_map
				<std::wstring, BomberMap::BlockType> _strBlk;
			int _mapSize;
			bomb::object::PowerFactory _factory;
			std::vector<object::ExplosionBlast> _explosionBlasts;
		};
	}
}

#endif /* CPP_INDIE_STUDIO_GAMEINFO_HPP */
