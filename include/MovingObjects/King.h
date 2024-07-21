#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "MovingObjects/MovingObjects.h"
#include "Define.h"

#include "MovingObjects/Player.h"


class King :public Player
{
public:
	static bool m_Win;
	King(Objects Icon, sf::Vector2f position);
	~King() {};
	
	

	void setWinLevel();
    static bool getWinLevel();
	
private:
	
};