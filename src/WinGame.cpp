#include "WinGame.h"



WinGame& WinGame::instance()
{
	static WinGame Wingame;
	return Wingame;
}



WinGame::WinGame()
{
	loadObjects();
}

void WinGame::loadObjects()
{

	m_gameWinBackground.setTexture(*Texture::instance().getGameWinBackGround());

	m_gameWinBackground.setScale(sf::Vector2f((M_WidthWindow / m_gameWinBackground.getGlobalBounds().width),
		(M_HieghtWindow / m_gameWinBackground.getGlobalBounds().height)));


	for (int i = 0; i < 2; i++)
	{
		m_menu[i].setFont(*Texture::instance().getFont());
		m_menu[i].setCharacterSize(100);
		m_menu[i].setStyle(sf::Text::Bold);
		m_menu[i].setColor(sf::Color::White);
		m_menu[i].setOutlineColor(sf::Color::Black);
		m_menu[i].setOutlineThickness(4);
		m_menu[i].setOutlineColor(sf::Color::Red);
	}


	m_menu[0].setString("Next level");
	m_menu[0].setPosition(sf::Vector2f(
		250, (800 / 2.5)));


	m_menu[1].setString("Exit The Game");
	m_menu[1].setPosition(sf::Vector2f(
		750, (800 / 2.5)));	
}

bool WinGame::run(sf::RenderWindow& m_window,bool& startagain)
{
	Music::instance().reSetMusicWinGame();
	while (m_window.isOpen())
	{
		m_window.clear();
		m_window.draw(*getBackground());
		for (int i = 0; i < 2; i++)
		{
			m_window.draw(m_menu[i]);
		}

		if (auto event = sf::Event{}; m_window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				m_window.close();
				break;
			case sf::Event::MouseButtonReleased:

				if (m_menugame.handleclick(m_window, m_menu[0]))
				{
					startagain = true;
					return true;
				}
				if (m_menugame.handleclick(m_window, m_menu[1]))
				{
					m_window.close();
				}
				break;
			case sf::Event::MouseMoved:
				for (int i = 0; i < 2; i++)
					m_menugame.setColorText(m_window, m_menu[i], m_window.mapPixelToCoords
					({ event.mouseButton.x, event.mouseButton.y }));
				break;
			}
		}
		m_window.display();
	}
	return false;
}

sf::Sprite* WinGame::getBackground()
{
	return  &m_gameWinBackground;
}



