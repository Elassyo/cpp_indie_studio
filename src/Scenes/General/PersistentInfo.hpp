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
		bool generateMap() const;

		void setFileName(const std::string &);
		void setPlayerNbr(int playerNbr);
		void setgenerateMap(bool gm);
		void setPlayerInfos(std::array<PlayerInfo, 4> playerInfos);
		void setPlayerInfos(int idx, PlayerInfo playerinfo);
	private:
		int _playerNbr;
		bool _generateMap;
		std::string _fileMap;
		std::array<PlayerInfo, 4> _playerInfos;
	};
}

#endif /* CPP_INDIE_STUDIO_PERSISTENTINFO_HPP */