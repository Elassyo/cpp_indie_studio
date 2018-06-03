//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// EventHandler.hpp
//

#ifndef CPP_INDIE_STUDIO_EVENTHANDLER_HPP
#define CPP_INDIE_STUDIO_EVENTHANDLER_HPP

#include <memory>

#include "../Interface/IEventScene.hpp"

namespace bomb {
	class EventHandler : virtual public irr::IEventReceiver {
	public:
		void injectScene(std::shared_ptr<scene::IEventScene>);
		bool OnEvent(const irr::SEvent &event) override;

	private:
		std::shared_ptr<scene::IEventScene> _evtScene;
	};
}

#endif /* CPP_INDIE_STUDIO_EVENTHANDLER_HPP */