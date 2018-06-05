//
// EPITECH PROJECT, 2018
// arcade
// File description:
// Clock.cpp
//

#include "Clock.hpp"

bomb::utils::Clock::Clock() :
	_lastReset(std::chrono::steady_clock::now()), _interval(0)
{
}

bomb::utils::Clock::Clock(const long interval) :
	_lastReset(std::chrono::steady_clock::now()), _interval(0)
{
	setTimerInterval(interval);
}

void bomb::utils::Clock::reset()
{
	_lastReset = std::chrono::steady_clock::now();
}

void bomb::utils::Clock::setTimerInterval(const long interval)
{
	_interval = interval;
}

unsigned long long bomb::utils::Clock::getElapsedTime() const
{
	return std::chrono::duration_cast<std::chrono::milliseconds>(
		std::chrono::steady_clock::now() - _lastReset).count();
}

bool bomb::utils::Clock::isReady() const
{
	return getElapsedTime() >= _interval;
}
