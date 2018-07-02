/*
** EPITECH PROJECT, 2018
** student
** File description:
** 02/07/18
*/

#include <iostream>
#include <fstream>
#include <string>
#include "Game.hpp"

void Console::Game::loadMap()
{
	int x = 0, y = 0;

	std::string line;
	std::ifstream myfile("assets/maps/map.txt");
	if (!myfile.is_open())
		throw std::logic_error("Open map.txt failed.");
	while (getline(myfile, line) && y <= _mapper->getSize().y) {
		std::cout << line << '\n';
		x = 0;
		for (auto elem = line.begin() ; elem != line.end() ; ++elem, x <= _mapper->getSize().x) {
			const int &id = *elem;
			auto &block = _mapper->getCase(Pos<int>(x, y));
			if (block)
				std::cerr << "non" << std::endl;
			++x;
		}
		++y;
	}
	myfile.close();
}