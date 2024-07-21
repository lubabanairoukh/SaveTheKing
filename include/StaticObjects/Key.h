#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "StaticObjects/StaticObjects.h"
#include "Define.h"

class Key :public StaticObjects
{
public:
	Key(Objects Icon, sf::Vector2f position) :
		StaticObjects(Icon, position)
	{};
	~Key() {};
	virtual void handleCollision(Player& player) override {
		if (player.getObjects() == ThiefObj)
		{
			if (keyFoundKey(player))
				m_isDisposed = true;
			return;
		}
		if (player.getObjects() == WarriorObj)
			return;
		player.handleCollision(*this);
	};
	bool keyFoundKey(Player& player)
	{
		if (static_cast<Thief&>(player).keyFound())
			return true;
		return false;
	
	};
	virtual void handleCollision(Enemy& e)override {
		e.handleCollision(*this);
	};
};