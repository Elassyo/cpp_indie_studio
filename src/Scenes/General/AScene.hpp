//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// AScene.hpp
//

#ifndef CPP_INDIE_STUDIO_ASCENE_HPP
#define CPP_INDIE_STUDIO_ASCENE_HPP

#include "../../Interface/IGameScene.hpp"
#include "PersistentInfo.hpp"

namespace bomb {
	namespace scene {
		class AScene : public IGameScene {
		public:
			AScene(PersistentInfo &_infos);
		protected:
			bomb::PersistentInfo &_infos;
		};
	}
}
#endif /* CPP_INDIE_STUDIO_ASCENE_HPP */