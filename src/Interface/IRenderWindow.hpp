/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
** IRenderWindow.hpp
*/

#ifndef CPP_INDIE_STUDIO_IRENDERWINDOW_HPP
#define CPP_INDIE_STUDIO_IRENDERWINDOW_HPP

namespace bomb {
	class IRenderWindow {
	public:
		virtual void refresh() = 0;
	};
}

#endif /* CPP_INDIE_STUDIO_IRENDERWINDOW_HPP */