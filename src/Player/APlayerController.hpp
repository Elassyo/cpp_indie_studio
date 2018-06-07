//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// APlayerController.hpp
//

#ifndef CPP_INDIE_STUDIO_APLAYERCONTROLLER_HPP
#define CPP_INDIE_STUDIO_APLAYERCONTROLLER_HPP

#include "../Map/Map.hpp"
#include "../Interface/IPlayerController.hpp"

namespace bomb {
	class APlayerController : virtual public IPlayerController {
	public:
		APlayerController();
		Actions requestMovement() override;
		void close() override;

	protected:
		Actions _action;
		bool _end;
	};
}

#endif /* CPP_INDIE_STUDIO_APLAYERCONTROLLER_HPP */