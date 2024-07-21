#pragma once
#include <array>
#include <string>
#include <SFML/Graphics.hpp>
#include "Define.h"


/*
*
* class that save in it all the pics of objects in the game
* return an specific pic
*
*/

class Texture
{
public:

	~Texture() = default;

	static Texture& instance();

	sf::Texture* getObjectTexture(Objects symbol);
	sf::Texture* getMusicTexture(int symbol);
	sf::Texture* getGameBackGround();
	sf::Texture* getGameOverBackGround();
	sf::Texture* getGameWinBackGround();
	sf::Texture* getAboutTheGame();
	sf::Font* getFont();

private:

	Texture();

	std::array<sf::Texture, NumOfObjects>m_ObjectTextures;
	std::array <std::string, NumOfObjects > texturesName;
	std::array < std::string, MUSICONOFF> m_MusicName;
	std::array<sf::Texture, MUSICONOFF> m_MusicTextures;

	sf::Texture m_gameBackGround;
	sf::Texture m_gameOverBackGround;
	sf::Texture m_gameWinBackGround;
	sf::Texture m_abouttheGame;
	sf::Font m_font;


	void loadTextures();
};