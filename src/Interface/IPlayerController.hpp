//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// IPlayerController.hpp
//

#ifndef CPP_INDIE_STUDIO_IPLAYERCONTROLLER_HPP
#define CPP_INDIE_STUDIO_IPLAYERCONTROLLER_HPP

namespace bomb {
	class IPlayerController {
	public:
		enum Actions {
			MV_UP = 0,
			MV_RIGHT = 90,
			MV_DOWN = 180,
			MV_LEFT = 270,
			UNDEFINED,
			PUT_BOMB,
			NONE
		};

		virtual void execute(const irr::core::vector2di &pos) = 0;
		virtual Actions requestMovement() = 0;
	};
}

#endif /* CPP_INDIE_STUDIO_IPLAYERCONTROLLER_HPP */