//
// EPITECH PROJECT, 2018
// cpp_indie_studio - CharacterLoader.hpp
// File description:
// Created by Gregory EPLE
//

#ifndef CPP_INDIE_STUDIO_CHARACTERLOADER_HPP
#define CPP_INDIE_STUDIO_CHARACTERLOADER_HPP

#include <map>

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
			std::string getCharacterPath(Character character);
			const wchar_t *getCharacterName(Character character);
			Character getNextCharacter(Character character);
			Character getPrevCharacter(Character character);

		private:
			std::map<Character, std::pair<const wchar_t *,
				std::string>>_characters;
		};
	}
}

#endif //CPP_INDIE_STUDIO_CHARACTERLOADER_HPP
