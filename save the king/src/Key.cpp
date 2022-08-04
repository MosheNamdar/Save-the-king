#include "Key.h"

#include "King.h"
#include "Thief.h"
#include "Warrior.h"
#include "Dwarf.h"
#include "Mage.h"

Key::Key(const sf::Vector2f& position, const sf::Vector2f& size)
	:StaticObject(position, size, &Resources::instance().getTexture(TextureType::Key))
{
}

void Key::handleCollision(GameObject& gameObject)
{
}

void Key::handleCollision(King& king)
{
	king.handleCollision(*this);
}

void Key::handleCollision(Mage& mage)
{
	mage.handleCollision(*this);
}

void Key::handleCollision(Thief& thief)
{
	if (!thief.getKey())
	{
		m_delete = true;
		thief.setKey();
	}
		
}

void Key::handleCollision(Warrior& warrior)
{
	warrior.handleCollision(*this);
}

void Key::handleCollision(Dwarf& dwarf)
{
	dwarf.handleCollision(*this);
}