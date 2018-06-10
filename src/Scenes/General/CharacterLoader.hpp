//
// EPITECH PROJECT, 2018
// cpp_indie_studio - CharacterLoader.hpp
// File description:
// Created by Gregory EPLE
//

#ifndef CPP_INDIE_STUDIO_CHARACTERLOADER_HPP
#define CPP_INDIE_STUDIO_CHARACTERLOADER_HPP

#include <map>
#include "CharacterInfo.hpp"
#include "../../Interface/IAssetManager.hpp"

namespace bomb {
	namespace game {
		enum Character {
			SHYGUY_WHITE,
			SHYGUY_BLACK,
			SHYGUY_RED,
			SHYGUY_BLUE,
			SELECT_BEGIN,
			MARIO,
			LUIGI,
			YOSHI,
			KOOPA,
			DRYBONES,
			LAKITU,
			SELECT_END
		};

		class CharacterLoader {
		public:
			CharacterLoader();
			void loadImages(IAssetManager &manager);
			void loadSounds(IAssetManager &manager);
			void unloadSounds(IAssetManager &manager);
			std::string getCharacterPath(Character character);
			std::string getCharacterImagePath(Character character);
			std::string getSfxPath(Character character);
			std::string getHitSfxPath(Character character);
			const wchar_t *getCharacterName(Character character);
			Character getNextCharacter(Character character);
			Character getPrevCharacter(Character character);
			irr::video::ITexture
			*getCharacterTexture(Character character);
		private:
			std::map<Character, CharacterInfo> _characters;
		};
	}
}

#endif //CPP_INDIE_STUDIO_CHARACTERLOADER_HPP
