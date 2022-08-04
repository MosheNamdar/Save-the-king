#include "IncreaseTime.h"

#include "King.h"
#include "Thief.h"
#include "Warrior.h"
#include "Mage.h"

IncreaseTime::IncreaseTime(const sf::Vector2f& position, const sf::Vector2f& size)
	:Gift(position, size, &Resources::instance().getTexture(TextureType::Gift))
{
}

void IncreaseTime::handleCollision(GameObject& gameObject)
{
}

void IncreaseTime::handleCollision(King& king)
{
	m_delete = true;
	king.handleCollision(*this);
}

void IncreaseTime::handleCollision(Mage& mage)
{
	m_delete = true;
	mage.handleCollision(*this);
}

void IncreaseTime::handleCollision(Thief& thief)
{
	m_delete = true;
	thief.handleCollision(*this);
}

void IncreaseTime::handleCollision(Warrior& warrior)
{
	m_delete = true;
	warrior.handleCollision(*this);
}

void IncreaseTime::handleCollision(Dwarf& dwarf)
{
}