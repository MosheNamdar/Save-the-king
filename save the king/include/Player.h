#pragma once
#include "MovingObject.h"

class Player : public MovingObject {
public:
	Player(sf::Texture* texture);

	void setDirection(const sf::Vector2f& direction);
	void stop();
	virtual void move(sf::Time delta) override;
	bool gotToThrone() const;
	bool deleteDwarfs() const;
	bool increaseTime() const;
	bool decreaseTime() const;
	void setGifts2False();
	
protected:
	bool m_isWon = false;
	bool m_removeDrwafs = false;
	bool m_increaseTime = false;
	bool m_decreaseTime = false;
	sf::Sound m_sound;
	
private:
	sf::Vector2f m_direction = STOPED;
};