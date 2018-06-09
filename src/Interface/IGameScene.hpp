/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
** IGameScene.hpp
*/

#ifndef CPP_INDIE_STUDIO_IGAMESCENE_HPP
	#define CPP_INDIE_STUDIO_IGAMESCENE_HPP

	#include "IRenderWindow.hpp"
	#include "IAssetLoader.hpp"
	#include "IEventScene.hpp"

namespace bomb {

	namespace scene {

		enum SceneStatus {
			BEGIN,
			CONTINUE,
			END
		};

		class IGameScene : virtual public IEventScene {
		public:
			virtual ~IGameScene() = default;

			virtual bomb::scene::SceneStatus
				start(IAssetLoader &loader) = 0;
			virtual SceneStatus loop(IAssetLoader &loader) = 0;
			virtual void save() = 0;
			virtual void reset(IAssetLoader &loader) = 0;
			virtual void clean(IAssetLoader &loader) = 0;
			virtual std::string nextScene() = 0;
			bool onEvent(const irr::SEvent &event) override = 0;
		};

	}

}

#endif /* CPP_INDIE_STUDIO_IGAMESCENE_HPP */
