#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "StaticObjects/StaticObjects.h"
#include "Define.h"

class Orc :public StaticObjects
{
public:
	Orc(Objects Icon, sf::Vector2f position) :
		StaticObjects(Icon, position)
	{};
	~Orc() {};
	virtual void handleCollision(Player& player) override {
		if (player.getObjects() == WarriorObj)
		{
			if (static_cast<Warrior&>(player).OrcFound())
				m_isDisposed = true;
			return;
		}
		player.handleCollision(*this);
	};
	virtual void handleCollision(Enemy& e)override {
		e.handleCollision(*this);
	};
	
};