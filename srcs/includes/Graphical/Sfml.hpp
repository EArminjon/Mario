/*
** EPITECH PROJECT, 2018
** student
** File description:
** 11/06/18
*/
#pragma once

#include <SFML/Graphics.hpp>
#include "Tools.hpp"
#include "Sprites.hpp"
#include "Fonts.hpp"

namespace Graphical {
	class Sfml : public Sprites, public Fonts {
	public:
		enum mod {
			FULLSCREEN,
			WINDOW,
		};
		/*
		 * Constructor & Destructor
		 */
		Sfml() : _zoom(1.0f) {};

		~Sfml()
		{
			close();
		};

		/*
		 * Tools
		 */
		void open(mod type)
		{
			if (!_window.isOpen()) {
				if (type == FULLSCREEN)
					_window.create(sf::VideoMode(1080, 720), "Game", sf::Style::Fullscreen);
				else if (type == WINDOW)
					_window.create(sf::VideoMode(1080, 720), "Game", sf::Style::Close | sf::Style::Resize);
				_window.setFramerateLimit(30);
				_screen.create(_window.getSize().x, _window.getSize().y);
				_windowType = type;
			}
		};
		void setScreen(const sf::Vector2u &size)
		{
			_screen.clear(sf::Color::Transparent);
			_screen.create(size.x, size.y);
		}

		void clear()
		{
			_window.clear(sf::Color::Black);
			_screen.clear(sf::Color::Transparent);
		};

		void display()
		{
			_window.draw(sf::Sprite(_screen.getTexture()));
			_screen.display();
			_window.display();
		}

		void text(const std::string &font_name, const std::string &line, const std::size_t &size, const sf::Color &textColor,  const sf::Vector2f &position, const mod &type = FULLSCREEN)
		{
			sf::Text text;
			std::unique_ptr<sf::Font> &font = getFont(font_name);

			text.setFont(*font);
			text.setString(line);
			text.setCharacterSize(size);
			text.setFillColor(textColor);
			text.setPosition(position);
			if (type == FULLSCREEN)
				_window.draw(text);
			else
				_screen.draw(text);
		}

		/*
		 * Getter / Setter / inline function
		 */
		inline bool isOpen() { return _window.isOpen(); };
		inline void close() { _window.close(); };
		inline sf::RenderWindow &getWindow() { return _window; };
		inline sf::RenderTexture &getScreen() { return _screen; };
		inline const mod &getWindowType() const { return _windowType; };
		inline const Console::Pos<int> &getMousePosition() const { return _mouse; };
		inline void setMousePosition(const Console::Pos<int> &pos) { _mouse = pos; };
		inline void setZoom(const float &zoom) { _zoom = zoom; };
		inline const float &getZoom() const { return _zoom; };
	private:
		std::map<const int, std::unique_ptr<sf::Sprite>> _buttons;
		sf::RenderWindow _window;
		sf::RenderTexture _screen;
		float _zoom;
		Console::Pos<int> _mouse{};
		mod _windowType;
	};
}