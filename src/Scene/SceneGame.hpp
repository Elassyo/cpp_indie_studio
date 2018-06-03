/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
** SceneGame.hpp
*/

#ifndef CPP_INDIE_STUDIO_SCENEGAME_HPP
#define CPP_INDIE_STUDIO_SCENEGAME_HPP

#include "../Interface/IGameScene.hpp"

namespace bomb {
	namespace scene {
		class SceneGame : public IGameScene {
		public:
			~SceneGame() override = default;
			bomb::scene::SceneStatus
			start(IAssetLoader &loader) override;
			SceneStatus loop(IAssetLoader &loader) override;
			void save() override;
			void reset(IAssetLoader &loader) override;
			void clean() override;
			std::string nextScene() override;
		private:
			irr::video::ITexture *_blocksTextures;
		};
	}
}

#endif /* CPP_INDIE_STUDIO_SCENEGAME_HPP */