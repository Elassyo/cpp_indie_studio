//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// Execption.hpp
//

#ifndef CPP_INDIE_STUDIO_EXECPTION_HPP
#define CPP_INDIE_STUDIO_EXECPTION_HPP

#include <stdexcept>
#include <string>

namespace bomb {
	class Exception : public std::exception {
	public:
		explicit Exception(
			const std::string &context = "Undefined",
			const std::string &message = "Unknown Error");

		const char *what() const throw() override;

	private:
		std::string _error;
	};
}

#endif /* CPP_INDIE_STUDIO_EXECPTION_HPP */
