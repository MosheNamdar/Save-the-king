#pragma once

#include "Resources.h"
#include "Macros.h"
class King;
class Mage;
class Thief;
class Warrior;
class Dwarf;
class Fire;
class IncreaseTime;
class DecreaseTime;
class RemoveDwarfs;
class Key;
class Ork;
class TeleportCell;
class Throne;
class Wall;
class Gate;

class GameObject {
public:
	GameObject(const sf::Vector2f &position , const sf::Vector2f &size, sf::Texture* texture);
	GameObject(sf::Texture* texture);

	void draw(sf::RenderWindow& window) const;
	void move(sf::Vector2f toMove);
	void init(sf::Vector2f position, sf::Vector2f size);
	bool checkCollision(const GameObject& other) const;
	sf::FloatRect getGlobalBounds() const;
	void setColorGreen();
	void setColorWhite();
	void setPosition(sf::Vector2f position);
	sf::Vector2f getPosition() const;

	virtual void handleCollision(GameObject& gameObject) = 0;
	virtual void handleCollision(King& gameObject) = 0;
	virtual void handleCollision(Mage& gameObject) = 0;
	virtual void handleCollision(Thief& gameObject) = 0;
	virtual void handleCollision(Warrior& gameObject) = 0;
	virtual void handleCollision(Dwarf& gameObject) = 0;
	virtual void handleCollision(Fire& gameObject) = 0;
	virtual void handleCollision(Gate& gameObject) = 0;
	virtual void handleCollision(IncreaseTime& gameObject) = 0;
	virtual void handleCollision(DecreaseTime& gameObject) = 0;
	virtual void handleCollision(RemoveDwarfs& gameObject) = 0;
	virtual void handleCollision(Key& gameObject) = 0;
	virtual void handleCollision(Ork& gameObject) = 0;
	virtual void handleCollision(TeleportCell& gameObject) = 0;
	virtual void handleCollision(Throne& gameObject) = 0;
	virtual void handleCollision(Wall& gameObject) = 0;

private:
	void setSize(sf::Vector2f size);

	sf::Sprite m_sprite;
};