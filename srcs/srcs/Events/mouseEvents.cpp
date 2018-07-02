/*
** EPITECH PROJECT, 2018
** student
** File description:
** 01/07/18
*/

#include "Core.hpp"

void Console::Core::zoomEvent(const sf::Event &event)
{
	sf::View view = _sfml->getScreen().getView();

	if (event.mouseWheelScroll.delta > 0)
		_sfml->setZoom(1.10f);
	else if (event.mouseWheelScroll.delta < 0)
		_sfml->setZoom(0.90f);
	view.zoom(_sfml->getZoom());
	_sfml->getScreen().setView(view);
}


void Console::Core::mouseEvent(const sf::Event &event)
{
	if (_page == GAME && event.type == sf::Event::MouseWheelScrolled)
		zoomEvent(event);
	else if (_page == GAME && event.type == sf::Event::MouseButtonPressed)
		return ;
}