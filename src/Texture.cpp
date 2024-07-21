#include "Texture.h"

//--------------------------Texture Constructor----------------------------------------

Texture::Texture()
{
	/*
	* set up the pics of every object
	*/

	loadTextures();

}

//-----------------------------------------------------------------------------------------------

void Texture::loadTextures()
{
	/*
	* save the name of pics of objects in array
	* save the pic of every static and moving objects
	*/
	
	texturesName = {
	   "King.png","Mage.png","Warrior.png","Thief.png",
	   "Fire.png", "Wall.png", "Key.png", "Gate.png", "Orc.png", "Telphore.png","ChairKing.png",
	   "Enemy.png","ThiefWith.png","Gift.png"
	};

	m_MusicName = { "musicon.png","musicoff.png" };
	m_gameBackGround.loadFromFile("background.png");
	m_gameOverBackGround.loadFromFile("34fmPl.jpg");
	m_gameWinBackGround.loadFromFile("NextLevel.png");
	m_abouttheGame.loadFromFile("AboutTheGame.png");
	m_font.loadFromFile("CHILLER.TTF");
	

	for (int i = 0; i < NumOfObjects; i++) {
		m_ObjectTextures[i].loadFromFile(texturesName[i]);
	}
	for (int i = 0; i < MUSICONOFF; i++)
	{
		m_MusicTextures[i].loadFromFile(m_MusicName[i]);
	}

}



//-----------------------------------------------------------------------------------------------

Texture& Texture::instance()
{
	/*
	*
	* make an static object of class and return it
	*
	*/

	static Texture texture;
	return texture;
}

//-----------------------------------------------------------------------------------------------

sf::Texture* Texture::getObjectTexture(Objects symbol)
{

	/*
	*
	*return an specific texture of an object
	*
	*/

	int index = (int)symbol;
	return &m_ObjectTextures[index];
}

sf::Texture* Texture::getMusicTexture(int symbol)
{

	/*
	*
	*return an specific texture of music
	*
	*/

	return &m_MusicTextures[symbol];
}

//-----------------------------------------------------------------------------------------------
sf::Font* Texture::getFont()
{
	return &m_font;
}
sf::Texture* Texture::getGameBackGround()
{

	/*
	*
	*return an specific texture of music
	*
	*/

	return &m_gameBackGround;
}
sf::Texture* Texture::getGameOverBackGround()
{

	/*
	*
	*return an specific texture of music
	*
	*/

	return &m_gameOverBackGround;
}

sf::Texture* Texture::getGameWinBackGround()
{
	return &m_gameWinBackGround;
}

sf::Texture* Texture::getAboutTheGame()
{

	/*
	*
	*return an specific texture of music
	*
	*/

	return &m_abouttheGame;
}