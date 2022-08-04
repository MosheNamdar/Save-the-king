#include "Thief.h"

#include "King.h"
#include "Warrior.h"
#include "Dwarf.h"
#include "Mage.h"

Thief::Thief(const sf::Vector2f& position, const sf::Vector2f& size)
	:Player(&Resources::instance().getTexture(TextureType::Thief))
{
}

bool Thief::getKey() const
{
	return m_key;
}

void Thief::setKey()
{
	m_key = true;
}

bool* Thief::getKeyPointer()
{
	return &m_key;
}

void Thief::handleCollision(GameObject& gameObject)
{
	if (&gameObject == this) return;
	//double dispatch
	gameObject.handleCollision(*this);
}

void Thief::handleCollision(King& king)
{
	king.stepBack();
}

void Thief::handleCollision(Mage& mage)
{
	mage.stepBack();
}

void Thief::handleCollision(Warrior& warrior)
{
	warrior.stepBack();
}

void Thief::handleCollision(Dwarf& dwarf)
{
	dwarf.stepBack();
}

void Thief::handleCollision(Fire& fire)
{
	stepBack();
}

void Thief::handleCollision(Gate& gate)
{
	if (m_key)
	{
		m_key = false;
		m_sound.setBuffer(Resources::instance().getSound(SoundType::Gate));
		m_sound.play();
	}	
	else
		stepBack();
}

void Thief::handleCollision(IncreaseTime& increaseTime)
{
	m_increaseTime = true;
	m_sound.setBuffer(Resources::instance().getSound(SoundType::Gift));
	m_sound.play();
}

void Thief::handleCollision(DecreaseTime& decreaseTime)
{
	m_decreaseTime = true;
	m_sound.setBuffer(Resources::instance().getSound(SoundType::Gift));
	m_sound.play();
}

void Thief::handleCollision(RemoveDwarfs& removeDwarf)
{
	m_removeDrwafs = true;
	m_sound.setBuffer(Resources::instance().getSound(SoundType::Gift));
	m_sound.play();
}

void Thief::handleCollision(Key& key)
{
	if (!m_key)
		m_key = true;
	
}

void Thief::handleCollision(Ork& ork)
{
	stepBack();
}

void Thief::handleCollision(TeleportCell& teleportCell)
{
}

void Thief::handleCollision(Throne& throne)
{
	stepBack();
}

void Thief::handleCollision(Wall& wall)
{
	stepBack();
}
