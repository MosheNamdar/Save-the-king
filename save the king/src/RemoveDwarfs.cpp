#include "RemoveDwarfs.h"

#include "King.h"
#include "Thief.h"
#include "Warrior.h"
#include "Mage.h"


RemoveDwarfs::RemoveDwarfs(const sf::Vector2f& position, const sf::Vector2f& size)
	:Gift(position, size, &Resources::instance().getTexture(TextureType::Gift))
{
}

void RemoveDwarfs::handleCollision(GameObject& gameObject)
{
}

void RemoveDwarfs::handleCollision(King& king)
{
	m_delete = true;
	king.handleCollision(*this);
}

void RemoveDwarfs::handleCollision(Mage& mage)
{
	m_delete = true;
	mage.handleCollision(*this);
}

void RemoveDwarfs::handleCollision(Thief& thief)
{
	m_delete = true;
	thief.handleCollision(*this);
}

void RemoveDwarfs::handleCollision(Warrior& warrior)
{
	m_delete = true;
	warrior.handleCollision(*this);
}

void RemoveDwarfs::handleCollision(Dwarf& dwarf)
{
}
