#include "Board.h"

Board::Board()
{
	initPlayers();
}

void Board::draw(sf::RenderWindow& window) 
{
	for (int i = 0; i < m_players.size(); i++)
		m_players[i]->draw(window);	

	for (int i = 0; i < m_statics.size(); i++)
		m_statics[i]->draw(window);

	for (int i = 0; i < m_dwarfs.size(); i++)
		m_dwarfs[i]->draw(window);

	m_info.draw(window);
}

void Board::nextPlayer()
{
	m_selected = Character((int(m_selected) + 1) % NUM_OF_CHARACTERS);

	m_players[int(m_selected)]->setColorGreen();
	for (int i = 0; i < m_players.size(); i++)
		if (int(m_selected) != i)
			m_players[i]->setColorWhite();
}

void Board::setPlayerDirection(const sf::Vector2f& direction)
{
	m_players[int(m_selected)]->setDirection(direction);
}

void Board::stopPlayer()
{
	m_players[int(m_selected)]->stop();
}

bool Board::update(const sf::Time& delta)
{
	//move - player
	move(*m_players[int(m_selected)], delta);
	
	//move - dwarfs
	for (int i = 0; i < m_dwarfs.size(); i++)
		move(*m_dwarfs[i], delta);

	//check - delete object
	std::erase_if(m_statics, [](auto& unmovable)
	{
		return unmovable->haveToDelete();
	});

	//check gift - remove dwarfs
	for(int i = 0; i < m_players.size(); i++)   
		if (m_players[i]->deleteDwarfs())
		{
			m_players[i]->setGifts2False();
			m_dwarfs.clear();
		}
	
	//check gift - increase time
	for(int i = 0; i < m_players.size(); i++)
		if (m_players[i]->increaseTime())
		{
			m_players[i]->setGifts2False();
			m_info.setIncreaseTime();
		}
	
	//check gift - decrease time
	for (int i = 0; i < m_players.size(); i++)
		if (m_players[i]->decreaseTime())
		{
			m_players[i]->setGifts2False();
			m_info.setDecreaseTime();
		}

	//check - level complete
	if (m_players[int(Character::King)]->gotToThrone())
		return true;
		
	return false;
}

void Board::loadLevel(const LevelMap& map, const sf::Vector2i& size, int seconds)
{
	m_dwarfs.clear();
	m_statics.clear();
	m_players.clear();

	initPlayers();

	m_info.setTime(seconds);

	sf::Vector2f objSize;
	objSize.x = WIN_W / size.y;
	objSize.y = (WIN_H - INFO_H)/ size.x;

	for (int r = 0; r < size.x; r++)
	{
		for (int c = 0; c < size.y; c++)
		{
			sf::Vector2f objPosition(objSize.x /2 +c*objSize.x, objSize.y/2 +r*objSize.y);
			switch (map[r][c])
			{
			case KING: 
				m_players[int(Character::King)]->init(objPosition, objSize);
				break;

			case MAGE:
				m_players[int(Character::Mage)]->init(objPosition, objSize);
				break;

			case THIEF:
				m_players[int(Character::Thief)]->init(objPosition, objSize);
				break;

			case WARRIOR:
				m_players[int(Character::Warrior)]->init(objPosition, objSize);
				break;

			case DWARFS:
				m_dwarfs.push_back(std::make_unique<Dwarf>(objPosition, objSize));
				break;

			case GATE:
				m_statics.push_back(std::make_unique<Gate>(objPosition, objSize));
				break;

			case ORK:
				m_statics.push_back(std::make_unique<Key>(objPosition, objSize* KEY_SCALE));
				m_statics.push_back(std::make_unique<Ork>(objPosition, objSize));
				break;

			case TELEPORT_CELL:
				if (!m_toConnect)
					m_toConnect = std::make_unique <TeleportCell>(objPosition, objSize);
				else
				{
					std::unique_ptr<TeleportCell>  temp = std::make_unique <TeleportCell>(objPosition, objSize);
					m_toConnect->setOther(temp.get());
					temp->setOther(m_toConnect.get());
					m_statics.push_back(std::move(m_toConnect));
					m_statics.push_back(std::move(temp));
					m_toConnect = nullptr;
				}
				break;

			case THRONE:
				m_statics.push_back(std::make_unique<Throne>(objPosition, objSize));
				break;

			case WALL:
				m_statics.push_back(std::make_unique<Wall>(objPosition, objSize));
				break;

			case FIRE:
				m_statics.push_back(std::make_unique<Fire>(objPosition, objSize));
				break;

			case INCREASE_TIME:
				m_statics.push_back(std::make_unique<IncreaseTime>(objPosition, objSize));
				break;

			case DECREASE_TIME:
				m_statics.push_back(std::make_unique<DecreaseTime>(objPosition, objSize));
				break;

			case REMOVE_DRWAFS:
				m_statics.push_back(std::make_unique<RemoveDwarfs>(objPosition, objSize));
				break;

			default:
				break;
			}
		}
	}
}

bool Board::noTime() const
{
	//check - level lost
	return (m_info.timeOver());
		
}

void Board::nextLevel()
{
	m_info.nextLevel();
}

void Board::initPlayers()
{
	m_players.push_back(std::make_unique<King>());
	m_players.push_back(std::make_unique<Mage>());
	std::unique_ptr<Thief> thief = std::make_unique<Thief>();
	m_info.setKeyPointer(thief->getKeyPointer());
	m_players.push_back(std::move(thief));
	m_players.push_back(std::make_unique<Warrior>());

	m_players[int(m_selected)]->setColorGreen();
}

void Board::move(MovingObject& obj, const sf::Time& delta)
{
	obj.move(delta);

	for (auto& player : m_players)
		if (obj.checkCollision(*player))
			obj.handleCollision(*player);
			
	for (auto& stat : m_statics)
		if (obj.checkCollision(*stat))
			obj.handleCollision(*stat);
			
	for (auto& dwarf : m_dwarfs)
		if (obj.checkCollision(*dwarf))
			obj.handleCollision(*dwarf);

}
