#include "Warrior.h"

#include "King.h"
#include "Thief.h"
#include "Dwarf.h"
#include "Mage.h"

Warrior::Warrior(const sf::Vector2f& position, const sf::Vector2f& size)
	:Player(&Resources::instance().getTexture(TextureType::Warrior))
{
}

void Warrior::handleCollision(GameObject& gameObject)
{
	if (&gameObject == this) return;
	//double dispatch
	gameObject.handleCollision(*this);
}

void Warrior::handleCollision(King& king)
{
	king.stepBack();
}

void Warrior::handleCollision(Mage& mage)
{
	mage.stepBack();
}

void Warrior::handleCollision(Thief& thief)
{
	thief.stepBack();
}

void Warrior::handleCollision(Dwarf& dwarf)
{
	dwarf.stepBack();
}

void Warrior::handleCollision(Fire& fire)
{
	stepBack();
}

void Warrior::handleCollision(Gate& gate)
{
	stepBack();
}

void Warrior::handleCollision(IncreaseTime& increaseTime)
{
	m_increaseTime = true;
	m_sound.setBuffer(Resources::instance().getSound(SoundType::Gift));
	m_sound.play();
}

void Warrior::handleCollision(DecreaseTime& decreaseTime)
{
	m_decreaseTime = true;
	m_sound.setBuffer(Resources::instance().getSound(SoundType::Gift));
	m_sound.play();
}

void Warrior::handleCollision(RemoveDwarfs& removeDwarf)
{
	m_removeDrwafs = true;
	m_sound.setBuffer(Resources::instance().getSound(SoundType::Gift));
	m_sound.play();
}

void Warrior::handleCollision(Key& key)
{
	stepBack();
}

void Warrior::handleCollision(Ork& ork)
{
	m_sound.setBuffer(Resources::instance().getSound(SoundType::Ork));
	m_sound.play();
}

void Warrior::handleCollision(TeleportCell& teleportCell)
{
}

void Warrior::handleCollision(Throne& throne)
{
	stepBack();
}

void Warrior::handleCollision(Wall& wall)
{
	stepBack();
}
