#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "StaticObjects/StaticObjects.h"
#include "Define.h"

class Gate :public StaticObjects
{
public:
	Gate(Objects Icon, sf::Vector2f position) :
		StaticObjects(Icon, position)
	{};
	~Gate() {};
	virtual void handleCollision(Player& player) override {
		if (player.getObjects() == ThiefObj)
		{
			if (gateFoundGate(player))
				m_isDisposed=true;
			return;
			
		}
		player.handleCollision(*this);
		
	};

	bool gateFoundGate(Player& player)
	{
		if (static_cast<Thief&>(player).gateFound())
			return true;
		return false;
	};
	virtual void handleCollision(Enemy& e)override {
		e.handleCollision(*this);
	};
};