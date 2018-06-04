/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
** SceneGame.hpp
*/

#ifndef CPP_INDIE_STUDIO_SCENEGAME_HPP
	#define CPP_INDIE_STUDIO_SCENEGAME_HPP

	#include "../../Interface/IGameScene.hpp"
	#include "Bomb.hpp"

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
			bool onEvent(const irr::SEvent &event) override;
		private:
			void explodeBombs();
			irr::video::ITexture *_blocksTextures;
			std::vector<std::unique_ptr<bomb::object::Bomb>> _bombs;
		};
	}
}

#endif /* CPP_INDIE_STUDIO_SCENEGAME_HPP */