#pragma once
#include "MovingObject.h"

class Dwarf : public MovingObject {
public:
	Dwarf(const sf::Vector2f& position, const sf::Vector2f& size);

	virtual void move(sf::Time delta);
	virtual void handleCollision(GameObject& gameObject) override;
	virtual void handleCollision(King& king) override;
	virtual void handleCollision(Mage& mage) override;
	virtual void handleCollision(Thief& thief) override;
	virtual void handleCollision(Warrior& warrior) override;
	virtual void handleCollision(Dwarf& dwarf) override { }
	virtual void handleCollision(Fire& fire) override;
	virtual void handleCollision(Gate& gate) override;
	virtual void handleCollision(IncreaseTime& increaseTime) override { }
	virtual void handleCollision(DecreaseTime& decreaseTime) override { }
	virtual void handleCollision(RemoveDwarfs& removeDwarf) override { }
	virtual void handleCollision(Key& key) override;
	virtual void handleCollision(Ork& ork) override;
	virtual void handleCollision(TeleportCell& teleportCell) override;
	virtual void handleCollision(Throne& throne) override;
	virtual void handleCollision(Wall& wall) override;


private:
	sf::Vector2f m_direction = STOPED;
	sf::Clock m_clock;

};