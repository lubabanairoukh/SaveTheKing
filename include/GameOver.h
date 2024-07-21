



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

#include "Toolbar.h"



class GameOver {


public:
	~GameOver() = default;
	static GameOver& instance();
	void loadObjects();
	bool run(sf::RenderWindow& m_window, bool&);
	sf::Sprite* getBackground();
private:
	GameOver();
	sf::Sprite m_GameOverBackground;
	MenuGame m_menugame;
	sf::Text m_menu[2];

};
