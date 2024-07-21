#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "StaticObjects/StaticObjects.h"
#include "Define.h"

class Fire :public StaticObjects
{
public:
	Fire(Objects Icon, sf::Vector2f position) :
		StaticObjects(Icon, position)
	{};
	~Fire() {};
	virtual void handleCollision(Player& player) override {
		if (player.getObjects() == MageObj) {
			Music::instance().reSetMusicMage();
			m_isDisposed = true;
			return;
		}
		player.handleCollision(*this);
	}
	virtual void handleCollision(Enemy& e)override {
		e.handleCollision(*this);
	};
};