/*
** EPITECH PROJECT, 2018
** student
** File description:
** 01/07/18
*/
#pragma once

#include <memory>
#include <SFML/Graphics.hpp>

namespace Graphical {
	class Sprites {
	public:
		bool createTexture(const int &index, const std::string &path, std::map<const int, std::unique_ptr<sf::Texture>> &map)
		{
			std::unique_ptr<sf::Texture> texture = std::make_unique<sf::Texture>();

			if (!texture->loadFromFile(path))
				return false;
			map[index] = std::move(texture);
			return true;
		};

		bool createSprite(const int &index, const std::string &path, std::map<const int, std::unique_ptr<sf::Sprite>> &spritesMap,
						  std::map<const int, std::unique_ptr<sf::Texture>> &texturesMap)
		{
			if (!createTexture(index, path, _textures))
				return false;
			spritesMap[index] = std::make_unique<sf::Sprite>(*texturesMap[index]);
			return true;
		};

		std::unique_ptr<sf::Sprite> &getBlock(const int &id)
		{
			if (!_sprites[id])
				throw std::logic_error("getBlock: Texture not found !");
			return _sprites[id];
		};

		inline bool createBlock(const int &id, const std::string &path) { return createSprite(id, path, _sprites, _textures); };

	protected:
		std::map<const int, std::unique_ptr<sf::Texture>> _textures;
		std::map<const int, std::unique_ptr<sf::Sprite>> _sprites;
		const std::string _picturePath = "assets/pictures/";
	};
}
