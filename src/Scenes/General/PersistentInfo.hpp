//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// PersistentInfo.hpp
//

#ifndef CPP_INDIE_STUDIO_PERSISTENTINFO_HPP
	#define CPP_INDIE_STUDIO_PERSISTENTINFO_HPP

	#include <string>
	#include <vector>
	#include "PlayerInfo.hpp"

namespace bomb {
	class PersistentInfo {
	public:
		PersistentInfo(int = 1, bool = true, const std::string & = "");

		const std::string &getFileName() const;
		int getPlayerNbr() const;
		std::array<PlayerInfo, 4> getPlayerInfos() const;
		PlayerInfo getPlayerInfos(int idx) const;
		float getVolume() const;
		int getMapSize() const;
		bool generateMap() const;
		bool MainMusic() const;
		void setVolume(float volume);
		void setFileName(const std::string &);
		void setPlayerNbr(int playerNbr);
		void setgenerateMap(bool gm);
		void setMainMusic(bool mainMusic);
		void setPlayerInfos(std::array<PlayerInfo, 4> playerInfos);
		void setPlayerInfos(int idx, PlayerInfo playerinfo);
		void setMapSize(int mapSize);

	private:
		int _mapSize;
		int _playerNbr;
		float _volume;
		bool _generateMap;
		bool _mainMusic;
		std::string _fileMap;
		std::array<PlayerInfo, 4> _playerInfos;
	};
}

#endif /* CPP_INDIE_STUDIO_PERSISTENTINFO_HPP */