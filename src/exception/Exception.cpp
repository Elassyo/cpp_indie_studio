//
// EPITECH PROJECT, 2018
// cpp_bombade
// File description:
// Exception.cpp
//

#include "Exception.hpp"

bomb::Exception::Exception(
	const std::string &context,
	const std::string &message)
{
	_error = context + ": "  + message;
}

const char *bomb::Exception::what() const throw()
{
	return _error.c_str();
}
