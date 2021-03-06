//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// CharacterInfo.hpp
//

#ifndef CPP_INDIE_STUDIO_CHARACTERINFO_HPP
#define CPP_INDIE_STUDIO_CHARACTERINFO_HPP

#include <string>
#include "irrlicht/irrlicht.h"

namespace bomb {
	namespace game {
		class CharacterInfo {
		public:
			CharacterInfo(
				const wchar_t *name,
				std::string modelPath,
				std::string iconPath,
				std::string sfxPath = "sfx/ploop.ogg",
				std::string hitSfxPath = "sfx/thwomp.ogg");
			const wchar_t *getName();
			std::string &getModelPath();
			std::string &getIconPath();
			std::string &getSfxPath();
			std::string &getHitSfxPath();
			irr::video::ITexture *getTexture() const;
			void setTexture(irr::video::ITexture *texture);
		private:
			const wchar_t *_name;
			std::string _modelPath;
			std::string _iconPath;
			std::string _sfxPath;
			std::string _hitSfxPath;
			irr::video::ITexture *_texture;
		};
	}
}

#endif /* CPP_INDIE_STUDIO_CHARACTERINFO_HPP */