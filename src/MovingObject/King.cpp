#include "MovingObjects/King.h"

bool King::m_Win = false;

King::King(Objects Icon, sf::Vector2f position)
	:Player(Icon, position)
{
	
}

void King::setWinLevel()
{
	m_Win = true;
}
bool King::getWinLevel()
{
	return m_Win;
}