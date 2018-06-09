/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
** SceneGame.hpp
*/

#ifndef CPP_INDIE_STUDIO_SCENECHARACTERMENU_HPP
	#define CPP_INDIE_STUDIO_SCENECHARACTERMENU_HPP

	#include "../../Interface/IGameScene.hpp"

	#include "../../Menu/Menu.hpp"
#include "../General/AScene.hpp"

namespace bomb {
	namespace scene {
		class SceneCharacterMenu : public AScene {
		public:
			SceneCharacterMenu(PersistentInfo &infos);

			~SceneCharacterMenu() override = default;

			bomb::scene::SceneStatus start(
				IAssetLoader &loader) override;
			SceneStatus loop(IAssetLoader &loader) override;
			void save() override;
			void reset(IAssetLoader &loader) override;
			void clean() override;
			std::string nextScene() override;

			bool onEvent(const irr::SEvent &event) override;

		private:
			void addPlayerButtons();
			void addGameButtons();
			void initModelPaths();
			void changePlayerType(int idx, wchar_t *model);
			bomb::menu::Menu _menu;
			bool _running;
			std::string _nextScene;
		};
	}
}

#endif /* CPP_INDIE_STUDIO_SCENECHARACTERMENU_HPP */