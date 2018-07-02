/*
** EPITECH PROJECT, 2018
** student
** File description:
** 01/07/18
*/

#include "Core.hpp"

void Console::Core::loopGame()
{
	_sfml->open(Graphical::Sfml::WINDOW);
	while (_sfml->isOpen()) {
		manageEvents();
		//_music->audioManager();
		_sfml->clear();
		switch (_page) {
			case MENU: break;
			case GAME: game(); break;
			case EXIT: _sfml->close();
			default: break;
		}
		_sfml->display();
	}
}