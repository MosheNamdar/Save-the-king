#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

const float WIN_W = 800;
const float WIN_H = 800;
const int INFO_H = WIN_W / 10;

const sf::Vector2f STOPED = { 0.f, 0.f };
const sf::Vector2f LEFT = { -1.f, 0.f };
const sf::Vector2f RIGHT = { 1.f, 0.f };
const sf::Vector2f UP = { 0.f, -1.f };
const sf::Vector2f DOWN = { 0.f, 1.f };
const sf::Vector2f DIRECTIONS[] = { STOPED , LEFT , RIGHT, UP, DOWN };

const float PIXEL_PER_SECONDS_PLAYERS = 100.f;
const float PIXEL_PER_SECONDS_DWARFS = 50.f;
const sf::Vector2f DEFAULT_POSITION = { 0.f, 0.f };
const sf::Vector2f DEFAULT_SIZE = { 1.f, 1.f };
const int NUM_OF_TEXTURES = 17;
const int NUM_OF_SOUNDS = 7;
const int NUM_OF_CHARACTERS = 4;
const int NUM_OF_DIRECTIONS = 5;
const int NUM_OF_TEXTS = 3;
const int CLOSE_TELEPORT_TIME = 4;
const float KEY_SCALE = .6f;
const float VOLUME = 20.f;
const std::string FONT_PATH = "C:/Windows/Fonts/Arial.ttf";
const std::string FILE_NAME = "Board.txt";


const char KING  = 'K';
const char MAGE = 'M';
const char THIEF = 'T';
const char WARRIOR = 'W';
const char DWARFS = '^';
const char GATE = '#';
const char KEY = 'F';
const char ORK = '!';
const char TELEPORT_CELL = 'X';
const char THRONE = '@';
const char WALL = '=';
const char FIRE = '*';
const char INCREASE_TIME = 'I';
const char DECREASE_TIME = 'D';
const char REMOVE_DRWAFS = 'R';



enum class Character {
    King,
    Mage,
    Thief,
    Warrior,
};

enum class MenuOpt {
    Start,
    Help,
    Exit,
};

const int START = 0;
const int HELP = 1;
const int EXIT = 2;

const std::string MENU_TEXTS[] = { "start", "help", "exit" };

const std::string TEXTURES[] = { "king.png", "mage.png", "thief.png", "warrior.png", "dwarf.png", 
                                 "gate.png", "key.png", "ork.png", "teleport.png",  "throne.png", 
                                 "wall.png", "fire.png", "gift.png", "background4.png", "help.png",
                                 "background5.png",  "win.png" };
                                

const std::string SOUNDS[] = {"background.wav", "wingame.wav", "backgroundmenu.wav", "gift.wav",
                              "fire.wav", "ork.wav", "gate.wav"};
                              

enum class TextureType {
    King,
    Mage,
    Thief,
    Warrior,
    Dwarfs,
    Gate,
    Key,
    Ork,
    TeleportCell,
    Throne,
    Wall,
    Fire,
    Gift,
    BackGround,
    Help,
    BackGroundBoard,
    Win,
};

enum class SoundType {
   BackGround,
   WinGame,
   BackGroundMenu,
   Gift,
   Fire,
   Ork,
   Gate,
};

const std::string INFO_TEXTS[] = { "Level - ", "Key - ", "Time - " };

enum class Information {
    Level,
    Key,
    Time,
};

const int NUM_OF_INFO = 3;
const float INFO_TEXT_W = WIN_W / NUM_OF_INFO;
const float INFO_TEXT_Y = WIN_H - (INFO_H / 2);
const float FIRST_INFO_TEXT_X = INFO_TEXT_W / 2;

const int GIFT_OF_TIME = 20;
