#include "King.h"
#include "Mage.h"
#include "Thief.h"
#include "Warrior.h"
#include "Dwarf.h"

King::King(const sf::Vector2f& position, const sf::Vector2f& size)
	:Player(&Resources::instance().getTexture(TextureType::King))
{
}


void King::handleCollision(GameObject& gameObject)
{
	if (&gameObject == this) return;
	//double dispatch
	gameObject.handleCollision(*this);
}

void King::handleCollision(Mage& mage)
{
	mage.stepBack();
}

void King::handleCollision(Thief& thief)
{
	thief.stepBack();
}

void King::handleCollision(Warrior& warrior)
{
	warrior.stepBack();
}

void King::handleCollision(Dwarf& dwarf)
{
	dwarf.stepBack();
}

void King::handleCollision(Fire& fire)
{
	stepBack();
}

void King::handleCollision(Gate& gate)
{
	stepBack();
}

void King::handleCollision(IncreaseTime& increaseTime)
{
	m_increaseTime = true;
	m_sound.setBuffer(Resources::instance().getSound(SoundType::Gift));
	m_sound.play();
}

void King::handleCollision(DecreaseTime& decreaseTime)
{
	m_decreaseTime = true;
	m_sound.setBuffer(Resources::instance().getSound(SoundType::Gift));
	m_sound.play();
}

void King::handleCollision(RemoveDwarfs& removeDwarf)
{
	m_removeDrwafs = true;
	m_sound.setBuffer(Resources::instance().getSound(SoundType::Gift));
	m_sound.play();
}

void King::handleCollision(Key& key)
{
	stepBack();
}

void King::handleCollision(Ork& ork)
{
	stepBack();
}

void King::handleCollision(TeleportCell& teleportCell)
{
}

void King::handleCollision(Throne& throne)
{
	m_isWon = true;
}

void King::handleCollision(Wall& wall)
{
	stepBack();
}