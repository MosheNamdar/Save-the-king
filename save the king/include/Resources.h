#pragma once
#include "Macros.h"


class Resources{
public:
	static Resources& instance();
	sf::Texture& getTexture(TextureType type);
	sf::Font& getFont();
	sf::SoundBuffer& getSound(SoundType type);

private:
	Resources();

	void buildTextures();
	void buildSounds();

	sf::Font m_font;
	std::vector <sf::Texture> m_textures;
	std::vector <sf::SoundBuffer> m_sounds;
};