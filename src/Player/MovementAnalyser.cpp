//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// MovementAnalyser.cpp
//

#include "MovementAnalyser.hpp"

void bomb::MovementAnalyser::reset()
{
	top = {false, 0};
	bot = {false, 0};
	left = {false, 0};
	right = {false, 0};
	bomb = false;
}
