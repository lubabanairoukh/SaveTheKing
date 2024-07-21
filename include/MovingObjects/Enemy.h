#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "MovingObjects/MovingObjects.h"
#include "Define.h"





class Enemy :public MovingObjects
{
public:

	Enemy(Objects Icon, sf::Vector2f position);
	~Enemy() {};
	virtual void move(sf::Time DeltaTime);

	virtual void handleCollision(GameObjects& )override;
	virtual void handleCollision(Enemy& ) override {};
	virtual void handleCollision(Player& )override;
	virtual void handleCollision(Wall& )override;
	virtual void handleCollision(Fire& )override;
	virtual void handleCollision(Gate& ) override;
	virtual void handleCollision(Orc& ) override;
	virtual void handleCollision(Key& )override;
	virtual void handleCollision(Telphore& )override;
	virtual void handleCollision(ChairKing& ) override;


private:
	sf::Vector2f m_direction;
	sf::Clock m_changeDircectionAlarm;
};