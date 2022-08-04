#include "Info.h"

Info::Info()
{
	for (int i = 0; i < NUM_OF_INFO; i++)
	{
		sf::Text text(INFO_TEXTS[i], Resources::instance().getFont());
		text.setOrigin(text.getGlobalBounds().width / 2, text.getGlobalBounds().height / 2);
		text.setPosition({ FIRST_INFO_TEXT_X + i * INFO_TEXT_W, INFO_TEXT_Y });
		m_texts.push_back(text);
	}
}

void Info::draw(sf::RenderWindow& window)
{
	updateTexts();

	for (auto& text : m_texts)
		window.draw(text);
}

void Info::setKeyPointer(bool* haveKey)
{
	m_haveKey = haveKey;
}

void Info::nextLevel()
{
	m_level++;
}

void Info::setTime(int seconds)
{
	m_seconds = seconds;
	m_clock.restart();
}

bool Info::timeOver() const
{
	return (m_countSeconds <= 0 && m_countSeconds != m_seconds);
}

void Info::setIncreaseTime()
{
	m_seconds += GIFT_OF_TIME;
}

void Info::setDecreaseTime()
{
	m_seconds -= GIFT_OF_TIME;
}


void Info::updateTexts()
{
	m_texts[int(Information::Level)].setString(INFO_TEXTS[int(Information::Level)] + std::to_string(m_level));
	m_texts[int(Information::Key)].setString(INFO_TEXTS[int(Information::Key)] + (*m_haveKey ? "yes" : "no"));
	m_countSeconds = !m_seconds ? m_clock.getElapsedTime().asSeconds() : m_seconds - m_clock.getElapsedTime().asSeconds();
	m_texts[int(Information::Time)].setString(INFO_TEXTS[int(Information::Time)] + std::to_string(m_countSeconds));
}
