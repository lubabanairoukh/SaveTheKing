#include "MovingObjects/Warrior.h"
#include "MovingObjects/King.h"
#include "MovingObjects/Mage.h"
#include "MovingObjects/Thief.h"
#include "Music.h"

Warrior::Warrior(Objects Icon, sf::Vector2f position)
	:Player(Icon, position)
{
}
bool Warrior::OrcFound()
{
	Music::instance().reSetMusicOrc();
	return true;
}
/*
void Warrior::move(sf::Time deltaTime)
{

	m_prevPos = m_Icon.getPosition();
	
	m_Icon.move(dirFromKey() * ShapeSpeed * deltaTime.asSeconds());
	if (outOfBounds())
	{
		moveToPrevPos();
	}

}
*/
