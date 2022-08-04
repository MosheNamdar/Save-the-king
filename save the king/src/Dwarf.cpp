#include "Dwarf.h"

#include "King.h"
#include "Thief.h"
#include "Warrior.h"
#include "mage.h"

Dwarf::Dwarf(const sf::Vector2f& position, const sf::Vector2f& size)
	:MovingObject(position, size, &Resources::instance().getTexture(TextureType::Dwarfs))
{
}

void Dwarf::move(sf::Time delta)
{
	if (m_clock.getElapsedTime().asSeconds() >= 1)
	{
		m_clock.restart();
		m_direction = DIRECTIONS[(rand() % NUM_OF_DIRECTIONS)];
	}
	GameObject::move(m_direction * PIXEL_PER_SECONDS_DWARFS * delta.asSeconds());
	MovingObject::setStepSize(m_direction * PIXEL_PER_SECONDS_DWARFS * delta.asSeconds());
}

void Dwarf::handleCollision(GameObject& gameObject)
{
	if (&gameObject == this) return;
	//double dispatch
	gameObject.handleCollision(*this);
}

void Dwarf::handleCollision(King& king)
{
	king.stepBack();
}

void Dwarf::handleCollision(Mage& mage)
{
	mage.stepBack();
}

void Dwarf::handleCollision(Thief& thief)
{
	thief.stepBack();
}

void Dwarf::handleCollision(Warrior& warrior)
{
	warrior.stepBack();
}

void Dwarf::handleCollision(Fire& fire)
{
	stepBack();
}

void Dwarf::handleCollision(Gate& gate)
{
	stepBack();
}

void Dwarf::handleCollision(Key& key)
{
	stepBack();
}

void Dwarf::handleCollision(Ork& ork)
{
	stepBack();
}

void Dwarf::handleCollision(TeleportCell& teleportCell)
{
	stepBack();
}

void Dwarf::handleCollision(Throne& throne)
{
	stepBack();
}

void Dwarf::handleCollision(Wall& wall)
{
	stepBack();
}

