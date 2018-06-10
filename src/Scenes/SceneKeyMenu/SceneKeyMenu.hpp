/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
** SceneGame.hpp
*/

#ifndef CPP_INDIE_STUDIO_SCENEKEYMENU_HPP
	#define CPP_INDIE_STUDIO_SCENEKEYMENU_HPP

	#include "../../Menu/Menu.hpp"

	#include "../General/AScene.hpp"

	#include "IrrKeyToStr.hpp"

namespace bomb {
	namespace scene {
		class SceneKeyMenu : public AScene {
		public:
			SceneKeyMenu(PersistentInfo &_infos);

			~SceneKeyMenu() override = default;

			bomb::scene::SceneStatus start(
				IAssetManager &loader) override;
			SceneStatus loop(IAssetManager &loader) override;
			void save() override;
			void reset(IAssetManager &loader) override;
			void clean(IAssetManager &loader) override;
			std::string nextScene() override;

			bool onEvent(const irr::SEvent &event) override;

		private:
			void createKeyButtons();
			void changePlayer();
			void setActionKey(const irr::SEvent &event);
			void updateKey(IPlayerController::Actions action);
			void updateKeys();
			irr::EKEY_CODE getKeyByAction(
				IPlayerController::Actions action);
			bomb::menu::Menu _menu;
			bool _running;
			std::string _nextScene;
			int _player;
			IPlayerController::Actions _ctrl;
			std::map<irr::EKEY_CODE,
				IPlayerController::Actions> _keys;
			IrrKeyToStr _keyToStr;
		};
	}
}

#endif /* CPP_INDIE_STUDIO_SCENEKEYMENU_HPP */