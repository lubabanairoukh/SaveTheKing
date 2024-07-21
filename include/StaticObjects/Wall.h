#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "StaticObjects/StaticObjects.h"
#include "Define.h"

class Wall :public StaticObjects
{
public:
	Wall(Objects Icon, sf::Vector2f position) :
		StaticObjects(Icon, position)
	{};
	~Wall() {};
	virtual void handleCollision(Player& player)override {
		player.handleCollision(*this);

	};
	virtual void handleCollision(Enemy& e)override {
		e.handleCollision(*this);
	};
};