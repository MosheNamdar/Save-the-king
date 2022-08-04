#pragma once
#include "Resources.h"

class Info {
public:
	Info();

	void draw(sf::RenderWindow &window);
	void setKeyPointer(bool* haveKey);
	void nextLevel();
	void setTime(int seconds);
	bool timeOver() const;
	void setIncreaseTime();
	void setDecreaseTime();

private:
	void updateTexts();

	bool* m_haveKey = nullptr;
	int m_level = 0;
	int m_seconds = 0;
	int m_countSeconds = 0;
	sf::Clock m_clock;
	std::vector<sf::Text> m_texts;
};