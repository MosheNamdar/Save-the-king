#include "TeleportCell.h"

#include "King.h"
#include "Thief.h"
#include "Warrior.h"
#include "Dwarf.h"
#include "Mage.h"

TeleportCell::TeleportCell(const sf::Vector2f& position, const sf::Vector2f& size)
	:StaticObject(position, size, &Resources::instance().getTexture(TextureType::TeleportCell))
{
}

void TeleportCell::setOther(TeleportCell* teleportCell)
{
	m_other = teleportCell;
}


void TeleportCell::setOpen(bool open)
{
	if(!open)
		m_clock.restart();
	m_open = open;
}

void TeleportCell::handleCollision(GameObject& gameObject)
{
}

void TeleportCell::handleCollision(King& king)
{
	if (isOpen())
	{
		king.setPosition(m_other->getPosition());
		setOpen(false);
		m_other->setOpen(false);
	}
}

void TeleportCell::handleCollision(Mage& mage)
{
}

void TeleportCell::handleCollision(Thief& thief)
{
	if (isOpen())
	{
		thief.setPosition(m_other->getPosition());
		setOpen(false);
		m_other->setOpen(false);
	}
}

void TeleportCell::handleCollision(Warrior& warrior)
{
	if (isOpen())
	{
		warrior.setPosition(m_other->getPosition());
		setOpen(false);
		m_other->setOpen(false);
	}
}

void TeleportCell::handleCollision(Dwarf& dwarf)
{
	dwarf.stepBack();
}

bool TeleportCell::isOpen()
{
	if (m_clock.getElapsedTime().asSeconds() > CLOSE_TELEPORT_TIME)
		m_open = true;
	return m_open;
}