#include "Menu.h"

Menu::Menu()
{
	m_sprite.setTexture(Resources::instance().getTexture(TextureType::BackGround));
	
	for (int i = 0; i < NUM_OF_TEXTS; i++)  
	{
		m_texts.push_back(sf::Text(MENU_TEXTS[i], Resources::instance().getFont()));
		m_texts[i].setOrigin(m_texts[i].getGlobalBounds().width/2, m_texts[i].getGlobalBounds().height / 2);
		m_texts[i].setPosition({ WIN_W / 2, WIN_H / (NUM_OF_TEXTS + 1) * (i + 1) });
	}
}

bool Menu::run(sf::RenderWindow& window)
{
	sf::Sound s;
	s.setBuffer(Resources::instance().getSound(SoundType::BackGroundMenu));
	s.setVolume(VOLUME);
	s.play();
	s.setLoop(true);
	while (window.isOpen())
	{
		window.clear();
		window.draw(m_sprite);
		for (int i = 0; i < NUM_OF_TEXTS; i++)
			window.draw(m_texts[i]);
		window.display();

		if (auto event = sf::Event {}; window.waitEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;

			case sf::Event::MouseButtonReleased:
				auto location = window.mapPixelToCoords(
					{ event.mouseButton.x, event.mouseButton.y });
				if (handleClick(window, location))
					return true;		
			}
		}

	}
	return false;
}

bool Menu::handleClick(sf::RenderWindow& window, const sf::Vector2f& location)
{
	for (int i = 0; i < NUM_OF_TEXTS; i++)
	{
		if (m_texts[i].getGlobalBounds().contains(location))
		{
			switch (i)
			{
			case START:
				return true;

			case HELP:
				help(window);
				m_sprite.setTexture(Resources::instance().getTexture(TextureType::BackGround));
				window.clear();
				window.draw(m_sprite);
				window.display();
				break;
			
			case EXIT:
				window.close();
					break;

			default:
				break;
			}
		}
	}
	return false;
}


void Menu::help(sf::RenderWindow& window)
{
	m_sprite.setTexture(Resources::instance().getTexture(TextureType::Help));

	window.clear();
	window.draw(m_sprite);
	window.display();

	while (window.isOpen())
	{
		if (auto event = sf::Event{}; window.waitEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;

			case sf::Event::MouseButtonReleased:
				return;
			}
		}
	}
}
