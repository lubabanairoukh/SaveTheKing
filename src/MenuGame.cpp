#include "MenuGame.h"


MenuGame::MenuGame()
{
    
}

void MenuGame::menurun(sf::RenderWindow& window)
{

    /*
    *
    * upload the text of every three options and set position 
    * run the menu game
    *
    */



    Music::instance().startMusic();
 
    sf::Texture tex;
    tex.loadFromFile("aa.jpg");
    m_background.setTexture(tex);
    m_background.setScale(sf::Vector2f((M_WidthWindow / m_background.getGlobalBounds().width),
        (M_HieghtWindow / m_background.getGlobalBounds().height)));

    m_aboutheGame.setTexture(*Texture::instance().getAboutTheGame());
    m_aboutheGame.setScale(sf::Vector2f((M_WidthWindow / m_background.getGlobalBounds().width),
        (M_HieghtWindow / m_background.getGlobalBounds().height)));



    for (int i = 0; i < MENUSTART; i++)
    {

        setTextInfo(m_menu[i]);
        m_menu[i].setCharacterSize(70); 
        m_menu[i].setOutlineColor(sf::Color::Red);
    }

    m_menu[0].setString("Start The Game");
    m_menu[0].setPosition(sf::Vector2f(
        550,250));


    m_menu[1].setString("About The Game");
    m_menu[1].setPosition(sf::Vector2f(
        550,350));


    m_menu[2].setString("Exit The Game");
    m_menu[2].setPosition(sf::Vector2f(
        550,450));

   
    setTextInfo(m_namegame);
    m_namegame.setCharacterSize(100);
    m_namegame.setString("SAVE THE KING");
    m_namegame.setPosition(sf::Vector2f(490, 50));



    setTextInfo(m_donegame);
    m_donegame.setCharacterSize(40);
    m_donegame.setString("CREATED BY: LUBABA NAIROUKH");
    m_donegame.setPosition(sf::Vector2f(0, 730));


    run(window);
}

void MenuGame::run(sf::RenderWindow& window)
{

    /*
    * 
    * run the menu game
    * 
    * 
    */


    while (window.isOpen())
    {
        window.clear();
        draw(window);

        if (auto event = sf::Event{}; window.waitEvent(event))
        {
            switch (event.type)
            {


            case sf::Event::Closed:
                window.close();
                break;


            case sf::Event::MouseMoved:

                for (int i = 0; i < MENUSTART; i++)
                    setColorText(window, m_menu[i], window.mapPixelToCoords
                    ({ event.mouseButton.x, event.mouseButton.y }));
                break;


            case sf::Event::MouseButtonReleased:

                auto location = window.mapPixelToCoords(
                    { event.mouseButton.x, event.mouseButton.y });
                if (handleclick(window, m_menu[0]))
                {
                    
                  Music::instance().pauseMusic();
                    return;
                }
                else {
                    if (handleclick(window, m_menu[2]))
                        window.close();
                    else
                    {
                        if (handleclick(window, m_menu[1]))
                            aboutTheGame(window);
                        else
                        {
                            Music::instance().MouseButtonReleased(location);
                        }
                    }
                }

                break;
            }

        }
        window.display();

    }
}


bool MenuGame:: handleclick(sf::RenderWindow& window, sf::Text rec)
{
    /*
    * 
    * cheack out if the player click on one of the postion
    * 
    */


    float mouseX = sf::Mouse::getPosition(window).x;
    float mouseY = sf::Mouse::getPosition(window).y;

    float btnPosX = rec.getPosition().x;
    float btnPosY = rec.getPosition().y;

    float btnxPosWidth = rec.getPosition().x + rec.getLocalBounds().width;
    float btnyPosHeight = rec.getPosition().y + rec.getLocalBounds().height;

    if (mouseX <btnxPosWidth && mouseX>btnPosX && mouseY <btnyPosHeight && mouseY> btnPosY)
        return true;

    return false;
}


void MenuGame::setColorText(sf::RenderWindow& window, sf::Text& m_menu1, sf::Vector2f LocationMouseMoved)
{
    /*
    *
    * cheack if the player click or was in one of the three option
    * change the colot if the out line depends of the user click there
    * or no
    *
    */


    if (handleclick(window, m_menu1))
    {
        m_menu1.setOutlineThickness(8);

        m_menu1.setOutlineColor(sf::Color::Red);

        window.draw(m_menu1);
    }
    else
    {
        m_menu1.setOutlineThickness(4);
        m_menu1.setOutlineColor(sf::Color::Blue);
        window.draw(m_menu1);
    }

}

void MenuGame::aboutTheGame(sf::RenderWindow& window)
{
    sf::Vector2f location;
    sf::Text m_return;
    
    m_return.setCharacterSize(30);
    setTextInfo(m_return);
    m_return.setString("Return To Menu Game");
    m_return.setPosition(sf::Vector2f(0, 50));
    while (window.isOpen())
    {
        window.clear();
        window.draw(m_aboutheGame);
        window.draw(m_return);

        if (auto event = sf::Event{}; window.waitEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::MouseButtonReleased:

              location = window.mapPixelToCoords(
                    { event.mouseButton.x, event.mouseButton.y });
                if (handleclick(window,m_return))
                {
                    return;
                }
                break;
            case sf::Event::MouseMoved:
                setColorText(window, m_return, window.mapPixelToCoords
                ({ event.mouseButton.x, event.mouseButton.y }));
            }


        }
        window.display();

    }


}

void MenuGame::setTextInfo(sf::Text& text_ic)
{
    text_ic.setFont(*Texture::instance().getFont());
    text_ic.setStyle(sf::Text::Bold);
    text_ic.setColor(sf::Color::White);
    text_ic.setOutlineColor(sf::Color::Black);
    text_ic.setOutlineThickness(4);
}


void MenuGame::draw(sf::RenderWindow& window)
{
    /*
    * draw the background of the menu game
    * draw the three option:
    * start the game 
    * about the game
    * exit
    * draw the music picture 
    * 
    */

 
    window.draw(m_background);
    window.draw(m_namegame);
    window.draw(m_donegame);
    for (int i = 0; i < 3; i++)
        window.draw(m_menu[i]);

    Music::instance().draw(window);
   
}