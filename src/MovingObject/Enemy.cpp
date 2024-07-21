
#include "MovingObjects/Enemy.h"

#include "MovingObjects/King.h"
#include "MovingObjects/Mage.h"
#include "MovingObjects/Thief.h"
#include "MovingObjects/Warrior.h"

Enemy::Enemy(Objects Icon, sf::Vector2f position)
	:MovingObjects(Icon, position)
{
	m_Objects = Icon;
}


void Enemy::move(sf::Time deltaTime)
{
	
	/*
	* move the Dwaft according to randomly way
	* save the previous move
	* cheack if the Dwaft went outside the window
	*/

	if (m_changeDircectionAlarm.getElapsedTime().asSeconds()> 1)
	{
		m_direction = dirFromKey((rand() % 4));
		m_changeDircectionAlarm.restart();
	}

	m_prevPos = m_Icon.getPosition();
	m_Icon.move(m_direction * ShapeSpeed * deltaTime.asSeconds());
	
	if (outOfBounds())
	{
		moveToPrevPos();
	}
	
}

void Enemy::handleCollision(GameObjects& gameObject)
{
	gameObject.handleCollision(*this);
}

void Enemy::handleCollision(Player& o)
{
	o.moveToPrevPos();
	
}

void Enemy::handleCollision(Wall& )
{
	moveToPrevPos();
	
}

void Enemy::handleCollision(Fire&)
{
	moveToPrevPos();
}

void Enemy::handleCollision(Gate& )
{
	moveToPrevPos();
	
}

void Enemy::handleCollision(Orc& )
{
	moveToPrevPos();
	
}

void Enemy::handleCollision(Key& )
{
	moveToPrevPos();

}

void Enemy::handleCollision(Telphore& )
{
	moveToPrevPos();
	
}

void Enemy::handleCollision(ChairKing& )
{
	moveToPrevPos();
	
}

