//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// PlayerInfo.hpp
//

#ifndef CPP_INDIE_STUDIO_PLAYERINFO2_HPP
	#define CPP_INDIE_STUDIO_PLAYERINFO2_HPP

	#include <utility>
	#include <unordered_map>
	#include <irrlicht/irrlicht.h>
	#include <map>
	#include "../../Interface/IPlayerController.hpp"
	#include "CharacterLoader.hpp"

namespace bomb {
	class PlayerInfo {
	public:
		PlayerInfo();

		bool isAI() const;
		game::Character getCharacter() const;
		IPlayerController::Actions getActionFromKey(
			irr::EKEY_CODE) const;
		std::map<irr::EKEY_CODE, IPlayerController::Actions>
		getKeys() const;

		void setKeys(
			std::map<irr::EKEY_CODE,
				IPlayerController::Actions> keys);
		void setIsAI(bool isAI);
		void setCharacter(game::Character character);
	private:
		bool _isAI;
		game::Character _character;
		std::map<irr::EKEY_CODE,
			IPlayerController::Actions> _keys;
	};
}

#endif /* CPP_INDIE_STUDIO_PLAYERINFO_HPP */