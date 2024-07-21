//#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <fstream>
#include <Windows.h>
#include "MenuGame.h"
#include "Board.h"
#include "Texture.h"
#include <memory>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include "Define.h"
#include "ControllerObjects.h"
#include "Toolbar.h"
#include "WinGame.h"
#include "GameOver.h"


/*
* 
* class that controll all the game
* run the menu game
* run the game
* exit the game
* 
*/

class GameController {


public:
	
	GameController();

	void run();
	bool handleGameOver();
	bool handleWingame();

	void draw();
	
	

private:
	ControllerObjects m_controlleObj;
	sf::RenderWindow m_window;
	MenuGame m_menugame;
	sf::Sprite m_background;
	
	sf::Sprite m_winLevels;
	sf::Clock clock;

	bool startagain;
	int m_Timer;
	
	
};