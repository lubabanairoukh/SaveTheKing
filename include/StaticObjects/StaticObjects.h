#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Texture.h"
#include "Define.h"
#include "GameObjects.h"
#include "MovingObjects/Player.h"

class StaticObjects :public GameObjects
{
public:
	StaticObjects(Objects Icon, sf::Vector2f position)
		:GameObjects(Icon, position)
	{
	};


	virtual ~StaticObjects() {};

	virtual void handleCollision(GameObjects& )override {  };
	virtual void handleCollision(Player&)override = 0;
	virtual void handleCollision(Enemy& e)override=0;
	virtual void handleCollision(Wall& )override {  };
	virtual void handleCollision(Orc&)override {  };
	virtual void handleCollision(Key&)override {  };
	virtual void handleCollision(Gate&)override {  };
	virtual void handleCollision(Telphore&)override {  };
	virtual void handleCollision(ChairKing&)override { };
	virtual void handleCollision(Fire&)override {  };
	
protected:
	
};