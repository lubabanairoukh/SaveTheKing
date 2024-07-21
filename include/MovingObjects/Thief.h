#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Define.h"
#include "MovingObjects/Player.h"
class Thief :public Player
{
public:
	Thief(Objects Icon, sf::Vector2f position);
	~Thief() {};
	void setKey(bool);
	bool gateFound();
	bool keyFound();
private:
	 bool m_key_have;
};