#pragma once
#include "Board.h"
#include "Menu.h"
#include <iostream>

class Controller {
public:
	Controller();

	void run();
	
private:
	bool runLevel();
	bool readLevel();
	void winGame();

	sf::RenderWindow m_window;
	Board m_board;
	std::ifstream m_file;
	Menu m_menu;
	sf::Sprite m_sprite;
	sf::Vector2i m_size;
	int m_seconds;
	std::vector<std::vector<char>> m_map;

};

sf::Vector2f keyToDir(sf::Keyboard::Key key);