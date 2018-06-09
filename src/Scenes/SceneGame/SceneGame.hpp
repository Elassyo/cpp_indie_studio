/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
** SceneGame.hpp
*/

#ifndef CPP_INDIE_STUDIO_SCENEGAME_HPP
	#define CPP_INDIE_STUDIO_SCENEGAME_HPP

	#include "Bomb.hpp"
	#include "../General/Game.hpp"
	#include "../General/AScene.hpp"

namespace bomb {
	namespace scene {
		class SceneGame : public AScene {
		public:
			SceneGame(PersistentInfo &_infos);

			~SceneGame() override = default;

			bomb::scene::SceneStatus start(
				IAssetLoader &loader) override;
			SceneStatus loop(IAssetLoader &loader) override;
			void save() override;
			void reset(IAssetLoader &loader) override;
			void clean(IAssetLoader &loader) override;
			std::string nextScene() override;

			bool onEvent(const irr::SEvent &event) override;

		private:
			void explodeBombs(bomb::IAssetLoader &loader);

			irr::video::ITexture *_blocksTextures;
			std::vector<std::unique_ptr<bomb::object::Bomb>> _bombs;
			bomb::game::Game _game;
			bool _running;
		};
	}
}

#endif /* CPP_INDIE_STUDIO_SCENEGAME_HPP */