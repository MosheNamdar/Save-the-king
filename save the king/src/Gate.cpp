#include "Gate.h"

#include "King.h"
#include "Thief.h"
#include "Warrior.h"
#include "Dwarf.h"
#include "Mage.h"

Gate::Gate(const sf::Vector2f& position, const sf::Vector2f& size)
	:StaticObject(position, size, &Resources::instance().getTexture(TextureType::Gate))
{
}

void Gate::handleCollision(GameObject& gameObject)
{
}

void Gate::handleCollision(King& king)
{
	king.handleCollision(*this);
}

void Gate::handleCollision(Mage& mage)
{
	mage.handleCollision(*this);
}

void Gate::handleCollision(Thief& thief)
{
	if (thief.getKey())
		m_delete = true;
	thief.handleCollision(*this);
}

void Gate::handleCollision(Warrior& warrior)
{
	warrior.handleCollision(*this);
}

void Gate::handleCollision(Dwarf& dwarf)
{
	dwarf.handleCollision(*this);
}