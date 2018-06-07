//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// MovementAnalyser.hpp
//

#ifndef CPP_INDIE_STUDIO_MOVEMENTANALYSER_HPP
#define CPP_INDIE_STUDIO_MOVEMENTANALYSER_HPP

#include <utility>

namespace bomb {
	struct MovementAnalyser {
		std::pair<bool, float> top;
		std::pair<bool, float> left;
		std::pair<bool, float> bot;
		std::pair<bool, float> right;
		bool bomb;

		void reset();
	};
}

#endif /* CPP_INDIE_STUDIO_MOVEMENTANALYSER_HPP */