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



class WinGame {


public:
	~WinGame() = default;
	static WinGame& instance();
	void loadObjects();
	bool run(sf::RenderWindow& m_window,bool&);
	sf::Sprite* getBackground();
private:
	WinGame();
	sf::Sprite m_gameWinBackground;
	MenuGame m_menugame;
	sf::Text m_menu[2];

};
