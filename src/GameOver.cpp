#include "GameOver.h"



GameOver& GameOver::instance()
{


	static GameOver Gameover;
	return Gameover;
}



GameOver::GameOver()
{
	loadObjects();

}

void GameOver::loadObjects()
{
    m_GameOverBackground.setTexture(*Texture::instance().getGameOverBackGround());

    m_GameOverBackground.setScale(sf::Vector2f((M_WidthWindow / m_GameOverBackground.getGlobalBounds().width),
        (M_HieghtWindow / m_GameOverBackground.getGlobalBounds().height)));

    for (int i = 0; i < MENUTEXT; i++)
    {
        m_menu[i].setFont(*Texture::instance().getFont());
        m_menu[i].setCharacterSize(70);
        m_menu[i].setStyle(sf::Text::Bold);
        m_menu[i].setColor(sf::Color::White);
        m_menu[i].setOutlineThickness(4);
        m_menu[i].setOutlineColor(sf::Color::Red);
    }


    m_menu[0].setString("Play the level again");
    m_menu[0].setPosition(sf::Vector2f(
        200, (800 / 2.5)));


    m_menu[1].setString("Exit The Game");
    m_menu[1].setPosition(sf::Vector2f(
        750, (800 / 2.5)));




}

bool GameOver::run(sf::RenderWindow& m_window, bool& startagain)
{
  

    Music::instance().reSetMusicGameOver();
    while (m_window.isOpen())
    {
        m_window.clear();
        m_window.draw(m_GameOverBackground);
        for (int i = 0; i < MENUTEXT; i++)
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

            case sf::Event::MouseMoved:

                for (int i = 0; i < MENUTEXT; i++)
                    m_menugame.setColorText(m_window, m_menu[i], m_window.mapPixelToCoords
                    ({ event.mouseButton.x, event.mouseButton.y }));
                break;

            case sf::Event::MouseButtonReleased:

                auto location = m_window.mapPixelToCoords(
                    { event.mouseButton.x, event.mouseButton.y });
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
            }
        }
        m_window.display();

    }
    return false;
}

sf::Sprite* GameOver::getBackground()
{
	return  &m_GameOverBackground;
}



