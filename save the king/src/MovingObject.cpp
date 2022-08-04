#include "MovingObject.h"

MovingObject::MovingObject(const sf::Vector2f& position, const sf::Vector2f& size, sf::Texture* texture)
	:GameObject(position, size, texture)
{
}

MovingObject::MovingObject(sf::Texture* texture)
	: GameObject(texture)
{
}

void MovingObject::setStepSize(const sf::Vector2f& stepSize)
{
	m_stepSize = stepSize;
}

void MovingObject::stepBack()
{
	GameObject::move(-m_stepSize);
}
