#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "StaticObjects/StaticObjects.h"
#include "Define.h"



class Telphore :public StaticObjects
{
public:
	Telphore(Objects Icon, sf::Vector2f position) :
		StaticObjects(Icon, position)
	{};
	~Telphore() {};
	virtual void handleCollision(Player& player) override
	{

		if(player.getObjects()!=MageObj)
			player.setposition(moveing());
		player.handleCollision(*this);
	};
	
	void setTwins(sf::Vector2f vec)
	{
		m_twins = vec;
	};
	sf::Vector2f getTwins()
	{
		return m_twins;
	};


	sf::Vector2f moveing()
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			return { m_twins.x + 50,m_twins.y };

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			return { m_twins.x - 50,m_twins.y };

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			return { m_twins.x,m_twins.y - 50 };

		return { m_twins.x,m_twins.y + 50 };

	};
	virtual void handleCollision(Enemy& e)override {
		e.handleCollision(*this);
	};

private:
	int m_wich;
	sf::Vector2f m_twins;
};