#include "Gifts.h"

void Gifts::initShape(sf::Vector2f location)
{
	
	shape.setTexture(*Texture::instance().getObjectTexture(GiftsObj));

	shape.setPosition(location);
	shape.scale((float)((SIZEPIC) / shape.getGlobalBounds().height),
		(float)((SIZEPIC) / shape.getGlobalBounds().width));
		
}

Gifts::Gifts(sf::Vector2f location)
{
	type = setGiftsObjects();
	initShape(location);
	
}

Gifts::~Gifts()
{

}

sf::Sprite const& Gifts::getShape() const
{
	
	return shape;
}

const int Gifts::getType() const
{
	return type;
}

void Gifts::update()
{

}

void Gifts::render(sf::RenderWindow& target)
{
	target.draw(shape);
}

const int Gifts::setGiftsObjects()
{

	int type = gifts::EnTime;

	int randValue = rand() % 100 + 1;
	if (randValue > 60 && randValue <= 80)
		type = gifts::DECTIME;
	else if (randValue > 80 && randValue <= 100)
		type = gifts::ERASEO;

	return type;
}
