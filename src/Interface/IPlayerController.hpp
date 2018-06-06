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
		virtual ~IObject() = default;

		virtual void launch() = 0;
	};
}

#endif /* CPP_INDIE_STUDIO_IPLAYERCONTROLLER_HPP */