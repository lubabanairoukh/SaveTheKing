#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <sstream>
#include <iomanip>
#include <locale>
#include "ControllerObjects.h"




class Toolbar
{
public:
	
	~Toolbar();

	static Toolbar& instance();

	void load();

	void updateLevel();
	void updateplayer();

	void draw(sf::RenderWindow&);
	void resetLevelNum();

	
	void update();
	int GetCountDown();
	void setCountDown(int timer = 60);
	void increastime() {
		m_countdown += 10;
	};
	void decreastime()
	{
		m_countdown -= 10;
	};



private:

	Toolbar();
	sf::Clock clock;
	int m_level;
	bool m_timelessLevel;
	int m_countdown;
	bool m_onetime = true;

	sf::Text m_playerNow;
	sf::Text m_stageTimeText;
	sf::Text m_levelText;


	std::array <std::string, 4 > m_playerName;
	sf::Sprite m_player_now;
	sf::RectangleShape rec_y;


};
