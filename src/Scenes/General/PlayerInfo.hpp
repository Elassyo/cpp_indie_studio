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

namespace bomb {
	class PlayerInfo {
	public:
		PlayerInfo();

		bool isAI() const;
		wchar_t *getModelPath() const;
		IPlayerController::Actions getActionFromKey(irr::EKEY_CODE)
		const;

		void setIsAI(bool isAI);
		void setModelPath(wchar_t *modelPath);
	private:
		bool _isAI;
		wchar_t *_modelPath;
		std::map<irr::EKEY_CODE,
			IPlayerController::Actions> _keys;
	};
}

#endif /* CPP_INDIE_STUDIO_PLAYERINFO_HPP */