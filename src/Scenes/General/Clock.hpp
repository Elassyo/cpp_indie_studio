//
// EPITECH PROJECT, 2018
// arcade
// File description:
// Clock.hpp
//

#ifndef ARCADE_CLOCK_HPP
	#define ARCADE_CLOCK_HPP

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
                        long getEllapsedTime() const;
                        bool isReady() const;
                private:
                        std::chrono::time_point<std::chrono::steady_clock> _lastReset;
                        long _interval;
                };
        }
}

#endif //ARCADE_CLOCK_HPP
