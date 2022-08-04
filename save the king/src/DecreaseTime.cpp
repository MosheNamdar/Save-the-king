#include "DecreaseTime.h"

#include "King.h"
#include "Thief.h"
#include "Warrior.h"
#include "Mage.h"

DecreaseTime::DecreaseTime(const sf::Vector2f& position, const sf::Vector2f& size)
	:Gift(position, size, &Resources::instance().getTexture(TextureType::Gift))
{
}

void DecreaseTime::handleCollision(GameObject& gameObject)
{
}

void DecreaseTime::handleCollision(King& king)
{
	m_delete = true;
	king.handleCollision(*this);
}

void DecreaseTime::handleCollision(Mage& mage)
{
	m_delete = true;
	mage.handleCollision(*this);
}

void DecreaseTime::handleCollision(Thief& thief)
{
	m_delete = true;
	thief.handleCollision(*this);
}

void DecreaseTime::handleCollision(Warrior& warrior)
{
	m_delete = true;
	warrior.handleCollision(*this);
}

void DecreaseTime::handleCollision(Dwarf& dwarf)
{
}




