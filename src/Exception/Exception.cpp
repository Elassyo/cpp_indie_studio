//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// Exception.cpp
//

#include "Exception.hpp"

bomb::Exception::Exception(
	const std::string &context,
	const std::string &message)
{
	_what = context + ": "  + message;
}

const char *bomb::Exception::what() const noexcept
{
	return _what.c_str();
}