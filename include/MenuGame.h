#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <fstream>
#include <Windows.h>
#include "Define.h"
#include <SFML/Audio.hpp>
#include "Music.h"


/*
* 
* class that creat the menu of the game it's from three option 
* start the game
* about the game
* exit
* the class contain the music of menu of the game
* background of the menu game
* a page about the game
* if exit then finish 
* start then return to game controller to start the game
* it's class control the menu game

*/



class MenuGame 
{
public:

	MenuGame();
	
	void draw(sf::RenderWindow& window);

	void menurun(sf::RenderWindow& window);
	void run(sf::RenderWindow& window);

	bool handleclick(sf::RenderWindow& window, sf::Text rec);

	void setColorText(sf::RenderWindow& window, sf::Text& m_menu1, sf::Vector2f LocationMouseMoved);

	void aboutTheGame(sf::RenderWindow& window);
	
	void setTextInfo(sf::Text& text_ic);


private:

	sf::Text m_menu[MenuStart];
	sf::Text m_namegame;
	sf::Text m_donegame;
	sf::Sprite m_background;
	sf::Sprite m_aboutheGame;

	sf::Sprite m_music[MUSICONOFF];

	sf::Sound m_sound;

	bool m_MusicOnOff;
};