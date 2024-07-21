#include "MovingObjects/King.h"
#include "MovingObjects/Mage.h"
#include "MovingObjects/Thief.h"
#include "MovingObjects/Warrior.h"

#include "Music.h"

Thief::Thief(Objects Icon, sf::Vector2f position)
	:Player(Icon, position)
{
	m_key_have = false;
	
}



void Thief::setKey(bool found)
{
	m_key_have = found;
}

bool Thief::gateFound()
{
	if (!m_key_have)
	{
		moveToPrevPos();
		return false;

	}
	
	m_Icon.setTexture(*Texture::instance().getObjectTexture(ThiefObj));
	Music::instance().reSetMusicKey();
	setKey(false);
	return true;
}

bool Thief::keyFound()
{

	if (m_key_have)
	{
		moveToPrevPos();
		return false;
	}

	m_Icon.setTexture(*Texture::instance().getObjectTexture(ThiefWithKey));
	Music::instance().reSetMusicKey();
	setKey(true);
	return true;
}
