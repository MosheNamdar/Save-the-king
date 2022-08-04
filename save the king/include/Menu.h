#pragma once
#include "Macros.h"
#include "Resources.h"

class Menu {
public:
	Menu();

	bool run(sf:: RenderWindow &window);
	
private:
	bool handleClick(sf::RenderWindow& window, const sf::Vector2f& location);
	void help(sf::RenderWindow& window);

	std::vector <sf::Text> m_texts;
    sf::Sprite m_sprite;
};