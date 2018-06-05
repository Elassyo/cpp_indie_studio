//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// IActivator.hpp
//

#ifndef CPP_INDIE_STUDIO_IACTIVATOR_HPP
	#define CPP_INDIE_STUDIO_IACTIVATOR_HPP

	#include "../../Map/Map.hpp"

	#include "GameInfo.hpp"

namespace bomb {
	namespace game {
		class AActivator {
		public:
			AActivator();
			bool tryToActivate(GameInfo &infos);
		protected:
			virtual bool isActivable(GameInfo &infos) = 0;
			virtual bool activate(GameInfo &infos) = 0;
		private:
			bool _activated;
		};
	}
}
#endif /* CPP_INDIE_STUDIO_IACTIVATOR_HPP */