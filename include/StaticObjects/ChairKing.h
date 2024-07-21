#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "StaticObjects/StaticObjects.h"
#include "Define.h"

class ChairKing :public StaticObjects
{
public:
	ChairKing(Objects Icon, sf::Vector2f position) :
		StaticObjects(Icon, position)
	{};
	~ChairKing() {};
	virtual void handleCollision(Player& player) override {
		if (player.getObjects() == KingObj)
		{
			static_cast<King&>(player).setWinLevel();
		}
		player.handleCollision(*this);
	};
	virtual void handleCollision(Enemy& e)override {
		e.handleCollision(*this);
	};
	
};