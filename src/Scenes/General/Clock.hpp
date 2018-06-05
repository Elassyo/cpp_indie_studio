//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// Clock.hpp
//

#ifndef CPP_INDIE_STUDIO_CLOCK_HPP
	#define CPP_INDIE_STUDIO_CLOCK_HPP

	#include <chrono>
	#include <iostream>

namespace bomb {
	namespace utils {
		class Clock {
		public:
			Clock();
			Clock(long interval);
			void reset();
			void setTimerInterval(long interval);
			unsigned long long getElapsedTime() const;
			bool isReady() const;

		private:
			std::chrono::time_point<std::chrono::steady_clock> _lastReset;
			long _interval;
		};
	}
}

#endif /* CPP_INDIE_STUDIO_CLOCK_HPP */
