//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// IActivator.hpp
//

#ifndef CPP_INDIE_STUDIO_IACTIVATOR_HPP
	#define CPP_INDIE_STUDIO_IACTIVATOR_HPP
	#include "Game.hpp"

namespace bomb {
	namespace game {
		class AActivator {
		public:
			AActivator();
			bool tryToActivate(Game &infos);
		protected:
			virtual bool isActivable(Game &infos) = 0;
			virtual bool activate(Game &infos) = 0;
		private:
			bool _activated;
		};
	}
}
#endif /* CPP_INDIE_STUDIO_IACTIVATOR_HPP */