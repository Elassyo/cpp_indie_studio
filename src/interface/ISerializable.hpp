//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// ISerializable.hpp
//

#ifndef CPP_INDIE_STUDIO_ISERIALIZABLE_HPP
#define CPP_INDIE_STUDIO_ISERIALIZABLE_HPP

#include <string>

namespace bomb {
	class ISerializable {
	public:
		virtual std::string toString() = 0;
	};
}

#endif /* CPP_INDIE_STUDIO_ISERIALIZABLE_HPP */