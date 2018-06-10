//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// APlayerController.hpp
//

#ifndef CPP_INDIE_STUDIO_APLAYERCONTROLLER_HPP
#define CPP_INDIE_STUDIO_APLAYERCONTROLLER_HPP

#include "../Map/BomberMap.hpp"
#include "../Interface/IPlayerController.hpp"

namespace bomb {
	class APlayerController : virtual public IPlayerController {
	public:
		APlayerController();
		Actions requestMovement() override;

	protected:
		bool _end;
		Actions _action;
	};
}

#endif /* CPP_INDIE_STUDIO_APLAYERCONTROLLER_HPP */