#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "MovingObjects/MovingObjects.h"
#include "Define.h"
#include "MovingObjects/Enemy.h"

class Player :public MovingObjects
{
public:

	Player(Objects Icon, sf::Vector2f position) :
		MovingObjects(Icon, position) {

	};
	~Player() {};

	virtual void handleCollision(GameObjects& gameObject)override
	{
		gameObject.handleCollision(*this);
	}
	virtual void handleCollision(Player& p )override {
		p.moveToPrevPos();
		
	}
	virtual void handleCollision(Wall&)override {
		moveToPrevPos();
	
	}
	virtual void handleCollision(Fire&)override {
		moveToPrevPos();
		
	}
	virtual void handleCollision(Telphore&)override{
	
	}
	virtual void handleCollision(Key&)override {
		moveToPrevPos();
	
	}
	virtual void handleCollision(ChairKing&)override {
		moveToPrevPos();
	
	}
	virtual void handleCollision(Orc&)override {
		moveToPrevPos();
		
	}
	virtual void handleCollision(Gate&)override {
		moveToPrevPos();
	
	}
	virtual void handleCollision(Enemy& e)override {
		e.moveToPrevPos();
	
	}

private:

};