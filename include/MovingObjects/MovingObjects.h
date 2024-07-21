#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Texture.h"
#include "Define.h"
#include "GameObjects.h"




enum class Direction
{
	Stay,
	Up,
	Down,
	Left,
	Right,
};

const sf::Vector2f DirectionVec[] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };


class MovingObjects :public GameObjects{
public:
	MovingObjects(Objects Icon, sf::Vector2f position);
	virtual ~MovingObjects() {};

	virtual void move(sf::Time DeltaTime);
	
	sf::Vector2f const& getSpriteLocation() const;

	bool outOfBounds() const;

	void setprevloc();
	sf::Vector2f getprevloc()const;

	void moveToPrevPos();
	bool collidesWith(const GameObjects& obj) const;

	void setposition(sf::Vector2f pos);

protected:
	
	sf::Vector2f m_prevPos;

	sf::Vector2f dirFromKey(int i = -1);

};