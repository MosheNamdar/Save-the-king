#pragma once
#include "GameObject.h"

class StaticObject : public GameObject{
public:
	StaticObject(const sf::Vector2f& position, const sf::Vector2f& size, sf::Texture* texture); 

	bool haveToDelete() const;

	virtual void handleCollision(Fire& fire) override { }
	virtual void handleCollision(Gate& gate) override { }
	virtual void handleCollision(IncreaseTime& increaseTime) override { }
	virtual void handleCollision(DecreaseTime& decreaseTime) override { }
	virtual void handleCollision(RemoveDwarfs& removeDwarf) override { }
	virtual void handleCollision(Key& key) override { }
	virtual void handleCollision(Ork& ork) override { }
	virtual void handleCollision(TeleportCell& teleportCell) override { }
	virtual void handleCollision(Throne& throne) override { }
	virtual void handleCollision(Wall& wall) override { }

	
protected:
	bool m_delete = false;
};