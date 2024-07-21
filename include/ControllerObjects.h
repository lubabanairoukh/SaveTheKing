#pragma once
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
#include "StaticObjects/StaticObjects.h"
#include "StaticObjects/Wall.h"
#include "Define.h"
#include "MovingObjects/MovingObjects.h"
#include "MovingObjects/Mage.h"
#include "MovingObjects/King.h"
#include "MovingObjects/Warrior.h"
#include "MovingObjects/Thief.h"
#include "Gifts.h"
#include "GameObjects.h"
#include "Toolbar.h"
#include "MovingObjects/Player.h"
#include "StaticObjects/ChairKing.h"
#include "StaticObjects/Fire.h"
#include "StaticObjects/Gate.h"
#include "StaticObjects/Key.h"
#include "StaticObjects/Telphore.h"
#include "StaticObjects/Orc.h"




class ControllerObjects {


public:
	static int m_xStart;
	static int  m_yStart;
	static int wichcharacter;

	ControllerObjects();

	void setLocationCharacter();
	void draw(sf::RenderWindow& window);
	void move(sf::Time tim);

	void checkCollisionWithStaticObject(MovingObjects& thisObj, sf::Time deltatime);
	void checkCollisionWithMovingObject(MovingObjects& thisObj, sf::Time deltatime);

	void setwichCharacter()
	{
		wichcharacter++;
		if (wichcharacter >3)
			wichcharacter = 0;
	}
	
	void restartTheObjects();


	void setMovingObjects(char c, sf::Vector2f position);
	void setStaticObjects(char c, sf::Vector2f position);
	void handleGifts(MovingObjects& thisObj);
	void giftsSet();
	
	 bool newlevel();
	 void eraseEnemy();
	 void setTelphore();
	 size_t tekphoretwins(size_t i);
	 void handleofTelphore(MovingObjects& thisObj);

private:
	
	std::vector<std::unique_ptr<StaticObjects>> m_staticobjects;
	std::vector<std::unique_ptr<MovingObjects>> M_MovingObjects;
	std::vector<Gifts> m_gifts;
	int maxGifts;
	sf::RectangleShape background;
	
};