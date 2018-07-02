/*
** EPITECH PROJECT, 2018
** student
** File description:
** 02/07/18
*/
#pragma once

#include <memory>
#include <map>
#include "Tools.hpp"
#include "Case.hpp"

namespace Console {
	class Map {
	public:
		Map(Pos<int> size) : _size(size)
		{
			for (int y = 0 ; y < _size.y ; ++y) {
				for (int x = 0 ; x < _size.x ; ++x) {
					Pos<int> pos(x, y);
					std::cerr << "Drop: " << x << ":" << y << std::endl;
					_map.emplace(std::pair<Pos<int>, std::unique_ptr<Case>>(pos, std::make_unique<Case>(pos)));
				}
			}
		};

		~Map()
		{};

		inline const Pos<int> &getSize() const { return _size; };
		inline const std::unique_ptr<Case> &getCase(const Pos<int> pos) { return _map[pos]; };
	private:
		std::map<Pos<int>, std::unique_ptr<Case>> _map;
		Pos<int> _size;
	};
}