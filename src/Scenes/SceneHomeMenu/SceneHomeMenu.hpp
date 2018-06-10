/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
** SceneGame.hpp
*/

#ifndef CPP_INDIE_STUDIO_SCENEHOMEMENU_HPP
	#define CPP_INDIE_STUDIO_SCENEHOMEMENU_HPP

	#include "../../Menu/Menu.hpp"
	#include "../General/AScene.hpp"

namespace bomb {
	namespace scene {
		class SceneHomeMenu : public AScene {
		public:
			SceneHomeMenu(PersistentInfo &_infos);

			~SceneHomeMenu() override = default;

			bomb::scene::SceneStatus start(
				IAssetManager &loader) override;
			SceneStatus loop(IAssetManager &loader) override;
			void save() override;
			void reset(IAssetManager &loader) override;
			void clean(IAssetManager &loader) override;
			std::string nextScene() override;

			bool onEvent(const irr::SEvent &event) override;

		private:
			void launchMainMusic(IAssetManager &loader);
			bomb::menu::Menu _menu;
			bool _running;
			std::string _nextScene;
		};
	}
}

#endif /* CPP_INDIE_STUDIO_SCENEHOMEMENU_HPP */