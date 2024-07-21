#include "MovingObjects/MovingObjects.h"

MovingObjects::MovingObjects(Objects Icon, sf::Vector2f position)
	:GameObjects(Icon,position)
{
	
	m_prevPos = position;
}


void MovingObjects::move(sf::Time deltaTime)
{
	/*
	* move the player accourding wich key has been pressed
	* save the previous move
	* cheack if the player went outside the window
	*/

	m_prevPos = m_Icon.getPosition();

	m_Icon.move(dirFromKey() * ShapeSpeed * deltaTime.asSeconds());

	if (outOfBounds())
	{
		moveToPrevPos();
	}

}

sf::Vector2f const& MovingObjects::getSpriteLocation() const
{
	return getSprite().getPosition();
}

void MovingObjects::setprevloc()
{
	m_prevPos = getSpriteLocation();
}

sf::Vector2f MovingObjects::getprevloc()const
{
	return m_prevPos;
}

bool MovingObjects::outOfBounds() const	
{
	if (m_Icon.getGlobalBounds().left < 0 ||
		m_Icon.getGlobalBounds().left + m_Icon.getGlobalBounds().width > M_WidthWindow ||
		m_Icon.getGlobalBounds().top < 0 ||
		m_Icon.getGlobalBounds().top +m_Icon.getGlobalBounds().height > M_HieghtWindow)
		return true;
	return false;
}

void MovingObjects::moveToPrevPos()
{
	m_Icon.setPosition(m_prevPos);
}


bool MovingObjects::collidesWith(const GameObjects& obj) const
{
	return m_Icon.getGlobalBounds().intersects(obj.getSprite().getGlobalBounds());
}

void MovingObjects::setposition(sf::Vector2f pos)
{
	m_Icon.setPosition(pos);
}

sf::Vector2f MovingObjects::dirFromKey(int index)
{
	if (index != -1)
	{
		return DirectionVec[index];
	}
	else
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			return DirectionVec[1];
		else
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
				return DirectionVec[0];
			else
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
					return DirectionVec[2];
				else
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
						return DirectionVec[3];
	}
	return { 0, 0 };
	
}
