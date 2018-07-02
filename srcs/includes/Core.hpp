/*
** EPITECH PROJECT, 2018
** student
** File description:
** 01/07/18
*/
#pragma once

#include "Tools.hpp"
#include "Sfml.hpp"
#include "Game.hpp"

namespace Console {
	class Core {
	public:
		enum PageType {
			MENU,
			GAME,
			EXIT,
		};

		Core() : _sfml(std::make_unique<Graphical::Sfml>()), _page(GAME) {};

		~Core() {
			_sfml->close();
		};

		void loadResources();
		void loopGame();
		void manageEvents();
		void switchResolution();
		void keyManager(const sf::Event &event);
		void moveMapView(const sf::Vector2f& offset);
		void mouseEvent(const sf::Event &event);
		void zoomEvent(const sf::Event &event);
		void game();
		void createGame();
		void printMap(const Console::Pos<int> &pos);
		float findMapScale(const Console::Pos<int> &pos);
	private:
		std::unique_ptr<Graphical::Sfml> _sfml;
		PageType _page;
		std::unique_ptr<Game> _game;
	};
}