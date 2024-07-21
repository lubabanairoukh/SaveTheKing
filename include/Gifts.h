#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include "Texture.h"



class Gifts
{


public:
	Gifts(sf::Vector2f location);
	virtual ~Gifts();

	//Accessor

	sf::Sprite const& getShape() const;
	const int getType() const;

	//Functions
	void update();
	void render(sf::RenderWindow& target);
	const int setGiftsObjects();

private:
	sf::Sprite shape;
	int type;

	void initShape(sf::Vector2f location);
};

