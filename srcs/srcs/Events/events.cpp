/*
** EPITECH PROJECT, 2018
** student
** File description:
** 01/07/18
*/

#include "Core.hpp"

void Console::Core::switchResolution()
{
	if (_sfml->getWindowType() == Graphical::Sfml::WINDOW) {
		_sfml->close();
		_sfml->open(Graphical::Sfml::FULLSCREEN);
	} else if (_sfml->getWindowType() == Graphical::Sfml::FULLSCREEN) {
		_sfml->close();
		_sfml->open(Graphical::Sfml::WINDOW);
	}
}

void Console::Core::moveMapView(const sf::Vector2f& offset)
{
	auto view = _sfml->getScreen().getView();
	view.move(offset);
	_sfml->getScreen().setView(view);
}

void Console::Core::keyManager(const sf::Event &event)
{
	switch (event.key.code) {
		case sf::Keyboard::Tab: switchResolution();	break;
		case sf::Keyboard::Escape : _page = MENU; break;
		case sf::Keyboard::Left : moveMapView({-1, 0}); break;
		case sf::Keyboard::Right : moveMapView({1, 0}); break;
		case sf::Keyboard::Down : moveMapView({0, 1}); break;
		case sf::Keyboard::Up : moveMapView({0, -1}); break;
		default: break;
	}
};

void Console::Core::manageEvents()
{
	sf::Event event{};

	while (_sfml->getWindow().pollEvent(event)) {
		if (event.type == sf::Event::Closed)
			_sfml->close();
		else if (event.type == sf::Event::KeyPressed)
			keyManager(event);
		else if (event.type == sf::Event::Resized) {
			_sfml->getWindow().setView(sf::View(sf::FloatRect(0, 0, event.size.width, event.size.height)));
			_sfml->setScreen({_sfml->getWindow().getSize().x, _sfml->getWindow().getSize().y});
		} else if (event.type == sf::Event::MouseButtonPressed || event.type == sf::Event::MouseWheelScrolled)
			mouseEvent(event);
	}
}