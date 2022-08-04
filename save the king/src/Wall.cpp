#include "Wall.h"

#include "King.h"
#include "Thief.h"
#include "Warrior.h"
#include "Dwarf.h"
#include "Mage.h"

Wall::Wall(const sf::Vector2f& position, const sf::Vector2f& size)
	:StaticObject(position, size, &Resources::instance().getTexture(TextureType::Wall))
{
}

void Wall::handleCollision(GameObject& gameObject)
{
}

void Wall::handleCollision(King& king)
{
	king.handleCollision(*this);
}

void Wall::handleCollision(Mage& mage)
{
	mage.handleCollision(*this);
}

void Wall::handleCollision(Thief& thief)
{
	thief.handleCollision(*this);
}

void Wall::handleCollision(Warrior& warrior)
{
	warrior.handleCollision(*this);
}

void Wall::handleCollision(Dwarf& dwarf)
{
	dwarf.handleCollision(*this);
}





