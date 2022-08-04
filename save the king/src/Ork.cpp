#include "Ork.h"

#include "King.h"
#include "Thief.h"
#include "Warrior.h"
#include "Dwarf.h"
#include "Mage.h"

Ork::Ork(const sf::Vector2f& position, const sf::Vector2f& size)
	:StaticObject(position, size, &Resources::instance().getTexture(TextureType::Ork))
{
}

void Ork::handleCollision(GameObject& gameObject)
{
}

void Ork::handleCollision(King& king)
{
	king.handleCollision(*this);
}

void Ork::handleCollision(Mage& mage)
{
	mage.handleCollision(*this);
}

void Ork::handleCollision(Thief& thief)
{
	thief.handleCollision(*this);
}

void Ork::handleCollision(Warrior& warrior)
{
	m_delete = true;
	warrior.handleCollision(*this);
}

void Ork::handleCollision(Dwarf& dwarf)
{
	dwarf.handleCollision(*this);
}
