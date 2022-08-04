#pragma once
#include "GameObject.h"


class MovingObject: public GameObject {
public:
	MovingObject(const sf::Vector2f& position, const sf::Vector2f& size, sf::Texture* texture);
	MovingObject(sf::Texture* texture);

	virtual void move(sf::Time delta) = 0;
	void setStepSize(const sf::Vector2f& stepSize);
	void stepBack();
	

private:
	sf::Vector2f m_direction = STOPED;
	sf::Vector2f m_stepSize = STOPED;
};