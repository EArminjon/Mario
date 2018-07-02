/*
** EPITECH PROJECT, 2018
** student
** File description:
** 01/07/18
*/

#include "Core.hpp"

float Console::Core::findMapScale(const Console::Pos<int> &pos)
{
	int max_y = pos.y, max_x = pos.x;
	float height = _sfml->getScreen().getSize().y, width = _sfml->getScreen().getSize().x;
	float scale = width / max_x;

	if (max_y * scale > height)
		scale = height / max_y;
	return (scale);
}

void Console::Core::printMap(const Console::Pos<int> &pos)
{
	(void) pos;
	const Pos<int> &size = _game->getMapper()->getSize();
	float scale = findMapScale(size);

	for (std::size_t y = 0 ; y < size.y; ++y) {
		for (std::size_t x = 0 ; x < size.x; ++x) {
			auto &block = _game->getMapper()->getCase(Pos<int>(x, y));
			auto &sprite = _sfml->getBlock(block->getId());
			sprite->setScale({scale / sprite->getTexture()->getSize().x, scale / sprite->getTexture()->getSize().y});
			sprite->setPosition({x * scale, y * scale});
			_sfml->getWindow().draw(*sprite);
		}
	}
}

void Console::Core::createGame()
{
	_game = std::move(std::make_unique<Console::Game>());
	_game->loadMap();
}

void Console::Core::game()
{
	printMap(Pos<int>(0, 0));
}