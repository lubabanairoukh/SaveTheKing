#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "MovingObjects/MovingObjects.h"
#include "Define.h"
#include "MovingObjects/Player.h"





class Warrior :public Player
{
public:
	Warrior(Objects Icon, sf::Vector2f position);
	~Warrior() {};
	bool OrcFound();
};