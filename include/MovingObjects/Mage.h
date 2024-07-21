#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "MovingObjects/Player.h"
#include "Define.h"

class Mage :public Player
{
public:
	Mage(Objects Icon, sf::Vector2f position);
	~Mage() {};
};