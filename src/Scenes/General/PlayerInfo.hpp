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
	#include "../../Interface/IPlayerController.hpp"

namespace bomb {
	class PlayerInfo {
	public:
		PlayerInfo();

		bool isAI() const;
		void setIsAI(bool isAI);
		const std::unordered_map<irr::EKEY_CODE,
			std::pair<IPlayerController::Actions, wchar_t *>> &
			getKeys() const;
		void setKeys(const std::unordered_map<irr::EKEY_CODE,
			std::pair<IPlayerController::Actions, wchar_t *>>
			&keys);
		wchar_t *getModelPath() const;
		void setModelPath(wchar_t *modelPath);
	private:
		bool _isAI;
		wchar_t *_modelPath;
		std::unordered_map<irr::EKEY_CODE,
			std::pair<bomb::IPlayerController::Actions,
				wchar_t *>> _keys;
	};
}

#endif /* CPP_INDIE_STUDIO_PLAYERINFO_HPP */