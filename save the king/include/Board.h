#pragma once
#include "King.h"
#include "Mage.h"
#include "Warrior.h"
#include "Thief.h"
#include "Gate.h"
#include "Key.h"
#include "Ork.h"
#include "TeleportCell.h"
#include "Throne.h"
#include "Wall.h"
#include "Fire.h"
#include "Dwarf.h"
#include "RemoveDwarfs.h"
#include "IncreaseTime.h"
#include "DecreaseTime.h"
#include "Info.h"

#include <fstream>
using LevelMap = std::vector<std::vector<char>>;

class Board {
public:
	Board();

	void draw(sf::RenderWindow& window);   
	void nextPlayer();
	void setPlayerDirection(const sf::Vector2f & direction);
	void stopPlayer();
	bool update(const sf::Time &delta);
	void loadLevel(const LevelMap& map, const sf::Vector2i& size, int seconds);
	bool noTime() const;
	void nextLevel();

private:
	void initPlayers();
	void move(MovingObject& obj, const sf::Time& delta);

	Character m_selected = Character::King;
	std::vector<std::unique_ptr <Player>> m_players;
	std::vector<std::unique_ptr <StaticObject>> m_statics;
	std::vector<std::unique_ptr <MovingObject>> m_dwarfs;
	std::unique_ptr<TeleportCell>  m_toConnect;
	Info m_info;
};