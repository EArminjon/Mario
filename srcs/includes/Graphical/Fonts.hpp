/*
** EPITECH PROJECT, 2018
** student
** File description:
** 01/07/18
*/
#pragma once

#include <SFML/Graphics.hpp>

namespace Graphical {
	class Fonts {
	public:
		std::unique_ptr<sf::Font> &getFont(const std::string &name)
		{
			if (_fonts.find(name) == _fonts.end())
				throw std::logic_error(std::string("Unknown font: ") + name);
			return _fonts[name];
		}

		void createFont(const std::string &key, const std::string &path)
		{
			std::unique_ptr<sf::Font> font = std::make_unique<sf::Font>();

			font->loadFromFile(_fontPath + path);
			_fonts[key] = std::move(font);
		}

		void createFont(const std::string &key, std::unique_ptr<sf::Font> &font)
		{
			_fonts[key] = std::move(font);
		}

	protected:
		std::map<const std::string, std::unique_ptr<sf::Font>> _fonts;
		const std::string _fontPath = "assets/fonts/";
	};
}