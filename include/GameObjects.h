#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Texture.h"
#include "Define.h"



class Enemy;
class Wall;
class Player;
class Fire;
class Orc;
class ChairKing;
class Gate;
class Key;
class Telphore;

/*
* class that it's base of static object class and 
* moving object class
*
*/


class GameObjects {


public:
	GameObjects(Objects Icon, sf::Vector2f position);

	virtual ~GameObjects() {};

	virtual sf::Sprite const& getSprite() const;

	virtual void draw(sf::RenderWindow& window);

	Objects getObjects();

	virtual void setObjects(Objects);

	virtual void handleCollision(GameObjects& ) = 0;
	virtual void handleCollision(Player&) = 0;
	virtual void handleCollision(Wall &) = 0;
	virtual void handleCollision(Telphore&) = 0;
	virtual void handleCollision(Orc&) = 0;
	virtual void handleCollision(Key&) = 0;
	virtual void handleCollision(Gate&) = 0;
	virtual void handleCollision(Fire&) = 0;
	virtual void handleCollision(ChairKing&) = 0;
	virtual void handleCollision(Enemy&) = 0;


	bool isDisposed() const
	{
		return m_isDisposed;
	}


protected:
	sf::Sprite m_Icon;

	Objects m_Objects;
	bool m_isDisposed = false;
};