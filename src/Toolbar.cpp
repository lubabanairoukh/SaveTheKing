#pragma once

#include "Toolbar.h"
#include "Texture.h"
#include "Define.h"


Toolbar::Toolbar()
	: m_level(0),m_timelessLevel(false)
{

	m_playerName = { "King","Mage","Warrior","Thief" };

}

Toolbar::~Toolbar()
{
}

void Toolbar::load()
{
	

	int size_x = ((Board::m_width * P_SIZE) - 200);
	int start_x = ControllerObjects::m_xStart + m_ToolBar;
	int start_y = ControllerObjects::m_yStart - SIZEY;
	rec_y = sf::RectangleShape(sf::Vector2f(size_x, P_SIZE));
	rec_y.setFillColor(sf::Color(220, 220, 220, 128));
	rec_y.setPosition(sf::Vector2f(start_x,start_y ));

	
	m_levelText.setString("Level:" + std::to_string(this->m_level));
	m_levelText.setFont(*Texture::instance().getFont());
	m_levelText.setCharacterSize(SIZECHARACTER);
	m_levelText.setPosition((start_x+ P_SIZE), start_y);
	m_levelText.setFillColor(sf::Color::Black);


	m_playerNow.setFont(*Texture::instance().getFont());
	m_playerNow.setCharacterSize(SIZECHARACTER);
	m_playerNow.setPosition((start_x + size_x / 3), start_y);
	m_playerNow.setFillColor(sf::Color::Black);
	


	m_player_now.setTexture(*Texture::instance().getObjectTexture(KingObj));

	m_player_now.setPosition((start_x + size_x / 3)+190, start_y);



	m_stageTimeText.setFont(*Texture::instance().getFont());
	m_stageTimeText.setCharacterSize(SIZECHARACTER);
	m_stageTimeText.setPosition((start_x + size_x / 3 * 2), start_y);
	m_stageTimeText.setFillColor(sf::Color::Black);

}

void Toolbar::updateLevel()
{
	m_level++;
	m_onetime = true;
		load();
		if (m_level == 1) {
			m_player_now.setScale((float)((TOOLBARPLAYER) / m_player_now.getGlobalBounds().height),
				(float)((TOOLBARPLAYER) / m_player_now.getGlobalBounds().width));
		}
}

void Toolbar::updateplayer()
{

	m_stageTimeText.setString("Time left:" + std::to_string(m_countdown));
	m_playerNow.setString("player is : " + m_playerName[ControllerObjects::wichcharacter]);


	switch (ControllerObjects::wichcharacter)
	{
	case 0:
		m_player_now.setTexture(*Texture::instance().getObjectTexture(KingObj));
		break;
	case 1:
		m_player_now.setTexture(*Texture::instance().getObjectTexture(MageObj));
		break;
	case 2:
		m_player_now.setTexture(*Texture::instance().getObjectTexture(WarriorObj));
		break;
	case 3:
		m_player_now.setTexture(*Texture::instance().getObjectTexture(ThiefObj));
		break;
	}

}

void Toolbar::draw(sf::RenderWindow& window)
{
	
	update();
	window.draw(rec_y);
	window.draw(m_levelText);
	window.draw(m_stageTimeText);
	window.draw(m_playerNow);
	window.draw(m_player_now);
	
}

void Toolbar::resetLevelNum()
{
	m_level = 0;
}

void Toolbar::update()
{
	int timer = clock.getElapsedTime().asSeconds();
	if (timer > 0) {
		m_countdown--;
		// do this instead:
		m_stageTimeText.setString("Time left:" + std::to_string(m_countdown));
		clock.restart();
	}

	if (m_countdown <= LEFTTIME && m_onetime)
	{
		Music::instance().reSetMusicGame();
		m_onetime = false;
	}

	updateplayer();
}

int Toolbar::GetCountDown()
{
	return m_countdown;
}

void Toolbar::setCountDown(int timer)
{
	m_countdown = timer;
	updateLevel();
}

Toolbar& Toolbar::instance()
{
	/*
	*
	* make an static object of class and return it
	*
	*/

	static Toolbar toolbar;
	return toolbar;
}

