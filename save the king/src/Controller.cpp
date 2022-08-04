#include "Controller.h"


Controller::Controller()
	: m_window(sf::VideoMode(WIN_W, WIN_H), "Set origin example")
{
    m_file.open(FILE_NAME);
    if (!m_file.is_open())
    {
        std::cout << "cannot open file" << std::endl;
        exit(EXIT_FAILURE);
    }
}

void Controller::run()
{
    while (m_window.isOpen() && m_menu.run(m_window))
    {
        readLevel();
        m_board.loadLevel(m_map, m_size, m_seconds);
        while (m_window.isOpen())
        {
            if (runLevel())
            {
                if (!readLevel())
                {
                    winGame();
                    return;
                }     
            }
            m_board.loadLevel(m_map, m_size, m_seconds);
        }     
    } 
}

bool Controller::runLevel()
{
    sf::Clock clock;
    sf::Sound s;

    s.setBuffer(Resources::instance().getSound(SoundType::BackGround));
    s.setVolume(VOLUME);
    s.play();
    s.setLoop(true);
    
    while (m_window.isOpen())
    {
        m_window.clear();
        m_sprite.setTexture(Resources::instance().getTexture(TextureType::BackGroundBoard));
        m_window.draw(m_sprite);
        m_board.draw(m_window);
        m_window.display();

        for (auto event = sf::Event{}; m_window.pollEvent(event);)
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                m_window.close();
                break;

            case sf::Event::KeyPressed:
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
                    m_board.nextPlayer();
                m_board.setPlayerDirection(keyToDir(event.key.code));
                break;

            case sf::Event::KeyReleased:
                m_board.stopPlayer();
                break;
            }

        }
        if (m_board.update(clock.restart()))
            return true;

        if(m_board.noTime())
            return false;
    }
    return false;
}

bool Controller::readLevel()
{
    m_board.nextLevel();
    m_map.clear();

    m_file >> m_size.x >> m_size.y >> m_seconds;
    if (m_file.eof())
        return false;

    m_file.get();  //enter

    for (int r = 0; r < m_size.x; r++)
    {
        std::vector<char> line;
        for (int c = 0; c < m_size.y; c++)
        {
            line.push_back(m_file.get());
        }
        m_map.push_back(line);
        m_file.get();
    }
   
    return true;
}

void Controller::winGame()
{
    sf::Sound s;
    s.setBuffer(Resources::instance().getSound(SoundType::WinGame));
    s.setVolume(VOLUME * 2);
    s.play();

    while (m_window.isOpen())
    {
        m_window.clear();
        m_sprite.setTexture(Resources::instance().getTexture(TextureType::Win));
        m_window.draw(m_sprite);
        m_window.display();
        for (auto event = sf::Event{}; m_window.pollEvent(event);)
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                m_window.close();
                break;
            }
        }
    }
}

sf::Vector2f keyToDir(sf::Keyboard::Key key)
{
    switch (key)
    {
    case sf::Keyboard::Key::Space:
        return STOPED;
        
    case sf::Keyboard::Key::Left:
        return LEFT;
       
    case sf::Keyboard::Key::Right:
        return RIGHT;
        
    case sf::Keyboard::Key::Down:
        return DOWN;
        
    case sf::Keyboard::Key::Up:
        return UP;
    }
    return STOPED;
}
