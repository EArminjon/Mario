/*
** EPITECH PROJECT, 2018
** student
** File description:
** 02/07/18
*/
#pragma once

#include "Map.hpp"

namespace Console {
	class Game {
	public:
		Game() : _mapper(std::make_unique<Map>(Pos<int>(22, 12))) {};
		~Game() {};
		inline const std::unique_ptr<Map> &getMapper() const { return _mapper; };
		void loadMap();
	private:
		std::unique_ptr<Map> _mapper;
	};
}