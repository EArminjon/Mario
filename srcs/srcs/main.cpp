/*
** EPITECH PROJECT, 2018
** student
** File description:
** 01/07/18
*/

#include "Core.hpp"

int main()
{
	Console::Core core;

	core.loadResources();
	core.createGame();
	core.loopGame();
	return 0;
}
