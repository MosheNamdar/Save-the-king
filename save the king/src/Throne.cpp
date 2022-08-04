#include "Throne.h"

#include "King.h"
#include "Thief.h"
#include "Warrior.h"
#include "Dwarf.h"
#include "Mage.h"

Throne::Throne(const sf::Vector2f& position, const sf::Vector2f& size)
	:StaticObject(position, size, &Resources::instance().getTexture(TextureType::Throne))
{
}

void Throne::handleCollision(GameObject& gameObject)
{
}

void Throne::handleCollision(King& king)
{
	king.handleCollision(*this);
}

void Throne::handleCollision(Mage& mage)
{
	mage.handleCollision(*this);
}

void Throne::handleCollision(Thief& thief)
{
	thief.handleCollision(*this);
}

void Throne::handleCollision(Warrior& warrior)
{
	warrior.handleCollision(*this);
}

void Throne::handleCollision(Dwarf& dwarf)
{
	dwarf.handleCollision(*this);
}
