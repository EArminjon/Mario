/*
** EPITECH PROJECT, 2018
** student
** File description:
** 02/07/18
*/
#pragma once

#include "Case.hpp"
#include "Tools.hpp"

namespace Console {
	class Case {
	public:
		Case(Pos<int> pos) : _pos(pos)
		{};

		~Case()
		{};

		inline void setId(const int &id) { _id = id; };
		inline const int &getId() const { return  _id; };
		inline const Pos<int> &getPos() const { return _pos; };
	private:
		Pos<int> _pos;
		int _id;
	};
}