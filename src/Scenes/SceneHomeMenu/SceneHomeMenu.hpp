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
				IAssetLoader &loader) override;
			SceneStatus loop(IAssetLoader &loader) override;
			void save() override;
			void reset(IAssetLoader &loader) override;
			void clean() override;
			std::string nextScene() override;

			bool onEvent(const irr::SEvent &event) override;

		private:
			bomb::menu::Menu _menu;
			bool _running;
			std::string _nextScene;
		};
	}
}

#endif /* CPP_INDIE_STUDIO_SCENEHOMEMENU_HPP */