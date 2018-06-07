//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// PersistentInfo.hpp
//

#ifndef CPP_INDIE_STUDIO_PERSISTENTINFO_HPP
#define CPP_INDIE_STUDIO_PERSISTENTINFO_HPP

#include <string>

namespace bomb {
	class PersistentInfo {
	public:
		PersistentInfo(int, bool, const std::string &);

		const std::string &getFileName() const;
		int getPlayerNbr() const;
		bool generateMap() const;

		void setFileName(const std::string &);
		void setPLayerNbr(int playerNbr);
		void setgenerateMap(bool gm);
	private:
		int _playerNbr;
		bool _generateMap;
		std::string _fileMap;
	};
}

#endif /* CPP_INDIE_STUDIO_PERSISTENTINFO_HPP */