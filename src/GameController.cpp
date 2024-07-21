#include "GameController.h"






GameController::GameController()
	:m_window(sf::RenderWindow(sf::VideoMode(M_WidthWindow, M_HieghtWindow),"Save The King", sf::Style::Close|sf::Style::Titlebar))
{
    m_window.setFramerateLimit(120);
    startagain = false;
    m_Timer = 0;
}

void GameController::run()
{


    sf::Vector2f location;
    m_menugame.menurun(m_window);
 
    m_background.setTexture(*Texture::instance().getGameBackGround());
    m_background.setScale(sf::Vector2f((M_WidthWindow / m_background.getGlobalBounds().width),
        (M_HieghtWindow / m_background.getGlobalBounds().height)));
  
    m_controlleObj.newlevel();
    
    do {
        
        m_Timer += TIME; 

        startagain = false;

        Music::instance().reSetMusic();

        m_controlleObj.setLocationCharacter();

        Toolbar::instance().setCountDown(m_Timer);

        while (m_window.isOpen())
        {
            const auto deltaTime = clock.restart();

            m_window.clear();

            draw();
            if (auto event = sf::Event{}; m_window.pollEvent(event))
            {

                switch (event.type)
                {

                case sf::Event::Closed:
                    m_window.close();
                    break;
                case sf::Event::MouseButtonReleased:
                    location = m_window.mapPixelToCoords(
                        { event.mouseButton.x, event.mouseButton.y });

                    Music::instance().MouseButtonReleased(location);
                    break;

                case sf::Event::KeyPressed:
                    if (event.key.code == sf::Keyboard::Space)
                    {
                        m_controlleObj.setwichCharacter();
                    }
                    break;

                }

            }
            m_controlleObj.move(deltaTime);



            if (King::m_Win)
            {
                if (handleWingame())
                {
                    m_window.display();
                    break;
                }
            }

            if (Toolbar::instance().GetCountDown() < 0) {
                if (handleGameOver()) {
                    m_window.display();
                    break;
                }
            }

            m_window.display();


        }
    } while (startagain);

}
bool GameController::handleGameOver()
{

    if (GameOver::instance().run(m_window, startagain))
    {
        m_controlleObj.restartTheObjects();
        return true;
    }
    return false;

}


bool GameController::handleWingame()
{
    if (m_controlleObj.newlevel()){
        if (WinGame::instance().run(m_window, startagain))
            return true;
        }
    else
    {
        sf::Texture sa;
        sa.loadFromFile("Winnn.jpg");

        m_winLevels.setTexture(sa);

        m_winLevels.setScale(sf::Vector2f((M_WidthWindow / m_winLevels.getGlobalBounds().width),
            (M_HieghtWindow / m_winLevels.getGlobalBounds().height)));
        Music::instance().reSetMusicWinallGame();

        while (m_window.isOpen())
        {

            m_window.clear();
            m_window.draw(m_winLevels);
         
            if (auto event = sf::Event{}; m_window.pollEvent(event))
            {
                switch (event.type)
                {

                case sf::Event::Closed:
                    m_window.close();
                    break;
                }

            }

            m_window.display();

        }

    }
    return false;

}


void GameController::draw()
{
    m_window.draw(m_background);
    Toolbar::instance().draw(m_window);

    m_controlleObj.draw(m_window);
    Music::instance().draw(m_window);
}




