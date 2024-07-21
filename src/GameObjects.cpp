#include "GameObjects.h"



GameObjects::GameObjects(Objects Icon, sf::Vector2f position)
{
	/*
	* 
	* upload the picture of every object and set up the sprite
	* set the scale and position of the sprite
	* set up the object icon
	* 
	*/

	m_Icon.setTexture(*(Texture::instance().getObjectTexture(Icon)));

	
	m_Icon.scale((float)(SIZEPIC / m_Icon.getGlobalBounds().width),
		(float)(SIZEPIC / m_Icon.getGlobalBounds().height));

	m_Icon.setPosition(position);
	m_Objects =Icon; 
	

}

Objects GameObjects::getObjects()
{
	/*
	* 
	* return the enum the object of the class
	* 
	*/

	return m_Objects;
}

void GameObjects::setObjects(Objects symbol)
{
	/*
	* 
	* set up the object 
	* 
	*/

	m_Objects = symbol;
}



sf::Sprite const& GameObjects::getSprite() const
{
	/*
	* 
	* return a specific sprite depends in the class
	* 
	*/

	return m_Icon;
}

void GameObjects::draw(sf::RenderWindow& window)
{
	/*
	* 
	* draw the object
	* 
	*/

	window.draw(getSprite());
}
