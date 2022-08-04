#include "Player.h"

Player::Player(sf::Texture* texture)
	: MovingObject(texture)
{
}

void Player::setDirection(const sf::Vector2f& direction)
{
	m_direction = direction;
}

void Player::stop()
{
	m_direction = STOPED;
}

void Player::move(sf::Time delta)
{
	GameObject::move(m_direction * PIXEL_PER_SECONDS_PLAYERS * delta.asSeconds());
	MovingObject::setStepSize(m_direction * PIXEL_PER_SECONDS_PLAYERS * delta.asSeconds());
}

bool Player::gotToThrone() const
{
	return m_isWon;
}

bool Player::deleteDwarfs() const
{
	return m_removeDrwafs;
}

bool Player::increaseTime() const
{
	return m_increaseTime;
}

bool Player::decreaseTime() const
{
	return m_decreaseTime;
}

void Player::setGifts2False()
{
	m_increaseTime = false;
	m_removeDrwafs = false;
	m_decreaseTime = false;
}
