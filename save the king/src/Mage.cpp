#include "Mage.h"

#include "King.h"
#include "Thief.h"
#include "Warrior.h"
#include "Dwarf.h"

Mage::Mage(const sf::Vector2f& position, const sf::Vector2f& size)
	:Player(&Resources::instance().getTexture(TextureType::Mage))
{
}

void Mage::handleCollision(GameObject& gameObject)
{
	if (&gameObject == this) return;
	//double dispatch
	gameObject.handleCollision(*this);
}

void Mage::handleCollision(King& king)
{
	king.stepBack();
}

void Mage::handleCollision(Thief& thief)
{
	thief.stepBack();
}

void Mage::handleCollision(Warrior& warrior)
{
	warrior.stepBack();
}

void Mage::handleCollision(Dwarf& dwarf)
{
	dwarf.stepBack();
}

void Mage::handleCollision(Fire& fire)
{
	m_sound.setBuffer(Resources::instance().getSound(SoundType::Fire));
	m_sound.play();
}

void Mage::handleCollision(Gate& gate)
{
	stepBack();
}

void Mage::handleCollision(IncreaseTime& increaseTime)
{
	m_increaseTime = true;
	m_sound.setBuffer(Resources::instance().getSound(SoundType::Gift));
	m_sound.play();
}

void Mage::handleCollision(DecreaseTime& decreaseTime)
{
	m_decreaseTime = true;
	m_sound.setBuffer(Resources::instance().getSound(SoundType::Gift));
	m_sound.play();
}

void Mage::handleCollision(RemoveDwarfs& removeDwarf)
{
	m_removeDrwafs = true;
	m_sound.setBuffer(Resources::instance().getSound(SoundType::Gift));
	m_sound.play();
}

void Mage::handleCollision(Key& key)
{
	stepBack();
}

void Mage::handleCollision(Ork& ork)
{
	stepBack();
}

void Mage::handleCollision(TeleportCell& teleportCell)
{
}

void Mage::handleCollision(Throne& throne)
{
	stepBack();
}

void Mage::handleCollision(Wall& wall)
{
	stepBack();
}
