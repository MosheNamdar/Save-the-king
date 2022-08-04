#pragma once
#include "StaticObject.h"

class TeleportCell : public StaticObject {
public:
	TeleportCell(const sf::Vector2f& position, const sf::Vector2f& size);

	void setOther(TeleportCell *teleportCell);
	void setOpen(bool open);
	virtual void handleCollision(GameObject& gameObject) override;
	virtual void handleCollision(King& king) override;
	virtual void handleCollision(Mage& mage) override;
	virtual void handleCollision(Thief& thief) override;
	virtual void handleCollision(Warrior& warrior) override;
	virtual void handleCollision(Dwarf& dwarf) override;


private:
	bool isOpen();

	TeleportCell* m_other;
	sf::Clock m_clock;
	bool m_open = true;
};