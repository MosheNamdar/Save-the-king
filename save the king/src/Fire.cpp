#include "Fire.h"

#include "King.h"
#include "Thief.h"
#include "Warrior.h"
#include "Dwarf.h"
#include "Mage.h"

Fire::Fire(const sf::Vector2f& position, const sf::Vector2f& size)
	:StaticObject(position, size, &Resources::instance().getTexture(TextureType::Fire))
{
}

void Fire::handleCollision(GameObject& gameObject)
{
}

void Fire::handleCollision(King& king)
{
	king.handleCollision(*this);
}

void Fire::handleCollision(Mage& mage)
{
	m_delete = true;
	mage.handleCollision(*this);
}

void Fire::handleCollision(Thief& thief)
{
	thief.handleCollision(*this);
}

void Fire::handleCollision(Warrior& warrior)
{
	warrior.handleCollision(*this);
}

void Fire::handleCollision(Dwarf& dwarf)
{
	dwarf.handleCollision(*this);
}
