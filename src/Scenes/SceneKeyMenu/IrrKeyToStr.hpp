//
// EPITECH PROJECT, 2018
// cpp_indie_studio - IrrKeyToStr.hpp
// File description:
// Created by Gregory EPLE
//

#ifndef CPP_INDIE_STUDIO_IRRKEYTOSTR_HPP
	#define CPP_INDIE_STUDIO_IRRKEYTOSTR_HPP

	#include <irrlicht/irrlicht.h>
	#include <map>

namespace bomb {
	class IrrKeyToStr {
	public:
		IrrKeyToStr();
		const wchar_t *operator[](irr::EKEY_CODE keyCode);

	private:
		std::map<irr::EKEY_CODE, const wchar_t *> _keys;
	};
}


#endif //CPP_INDIE_STUDIO_IRRKEYTOSTR_HPP
