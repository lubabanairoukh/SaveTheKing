#include "ControllerObjects.h"

int ControllerObjects::wichcharacter = 0;
int ControllerObjects::m_xStart = 0;
int ControllerObjects::m_yStart = 0;



ControllerObjects::ControllerObjects()
{
    maxGifts = 0;
    wichcharacter = 0;
}

void ControllerObjects::setLocationCharacter()
{
    background = sf::RectangleShape(sf::Vector2f((Board::instance().getWidthMap() * 50)
        , (Board::instance().getHeightMap() * 49)));

     m_xStart = ((M_WidthWindow - (P_SIZE * Board::instance().getWidthMap())) / 2);
     m_yStart = (((M_HieghtWindow- m_ToolBar) - (P_SIZE * Board::instance().getHeightMap())) / 2)+70;
    background.setFillColor(sf::Color(255, 255, 255, 128));
    background.setPosition(sf::Vector2f(m_xStart, m_yStart +5));
    
  
    giftsSet();
    
    sf::Vector2f position;
    float xLoc, yLoc;
    for (int row = 0; row < Board::instance().getHeightMap(); row++)
    {
        for (int col = 0; col < Board::instance().getWidthMap(); col++)
        {
           

            xLoc = P_SIZE *col + m_xStart;

            yLoc = P_SIZE *row + m_yStart;
       
            position = { xLoc, yLoc };

            char c = Board::instance().getCharMap(row, col);
            setStaticObjects(c, position);
            setMovingObjects(c, position);
        }
    }
   
    setTelphore();
 
}

void ControllerObjects::setStaticObjects(char c, sf::Vector2f position)
{
    switch (c)
    {
    case '=':
        m_staticobjects.push_back(std::make_unique<Wall>(WallObj, position));
        return;
        
    case '*':
        m_staticobjects.push_back(std::make_unique<Fire>(FireObj, position));
        return;
    case 'F':
        m_staticobjects.push_back(std::make_unique<Key>(KeyObj, position));
        return;
    case '!':
        m_staticobjects.push_back(std::make_unique<Orc>(OrcObj, position));
        return;
    case '@':
        m_staticobjects.push_back(std::make_unique<ChairKing>(ChairKingObj, position));
        return;
    case 'X':
        m_staticobjects.push_back(std::make_unique<Telphore>(TelObj, position));
        return;
    case '#':
        m_staticobjects.push_back(std::make_unique<Gate>(GateObj, position));
        return;
    default:
        return;
    }
}


void ControllerObjects::setMovingObjects(char c,sf::Vector2f position)
{
    switch (c)
    {
    case 'M':
        M_MovingObjects.push_back(std::make_unique<Mage>(MageObj, position));
        return;
    case 'K':
        M_MovingObjects.push_back(std::make_unique<King>(KingObj, position));
        return;
    case 'T':
        M_MovingObjects.push_back(std::make_unique<Thief>(ThiefObj, position));
        return;
    case 'W':
        M_MovingObjects.push_back(std::make_unique<Warrior>(WarriorObj, position));
        return;
    case '^':
        M_MovingObjects.push_back(std::make_unique<Enemy>(EnemyObj, position));
      return;
    default:
        break;
    }
}



void ControllerObjects::draw(sf::RenderWindow& window)
{
  
    window.draw(background);
    for (int i = 0; i < m_gifts.size(); i++)
    {
        window.draw(m_gifts[i].getShape());
    }
    for (int i = 0; i < m_staticobjects.size(); i++)
    {
     
            window.draw(m_staticobjects[i]->getSprite());
    }
    
    for (int i = 0; i < M_MovingObjects.size(); i++)
    {
       window.draw(M_MovingObjects[i]->getSprite());
    }
   
    
   
}

bool ControllerObjects::newlevel()
{
    if (Board::instance().finishAllLevels())
        return false;

    restartTheObjects();
    wichcharacter = 0;
   

    Board::instance().readlevel();
    maxGifts += 3;
    return true;
}


void ControllerObjects::move(sf::Time time)
{


    /*
    * move accourding in wich character we are
    * cheack if Collision with static moving
    */
    
   
    
    for (auto& moving : M_MovingObjects)
    {

        if ((int)moving->getObjects() == wichcharacter || moving->getObjects() == EnemyObj)
        {

            moving->move(time);
            checkCollisionWithStaticObject(*moving, time);
            checkCollisionWithMovingObject(*moving, time);
            if ((int)moving->getObjects() == wichcharacter)
                handleGifts(*moving);

        }
    }
    
}
void ControllerObjects::checkCollisionWithStaticObject
(MovingObjects& thisObj, sf::Time deltatime)
{

    // check collision between player and enemies
    for (auto& movable : m_staticobjects)
    {

        if (thisObj.collidesWith(*movable))
        {

            Objects  objec = movable->getObjects();
            Objects objec_moving = thisObj.getObjects();

            if (objec_moving == WarriorObj)
            {
                thisObj.handleCollision(*movable);
                if(movable->isDisposed())
                      movable = std::make_unique<Key>(KeyObj, movable->getSprite().getPosition());

            }
            else
            {
                thisObj.handleCollision(*movable);
            }
            if (objec == TelObj)
            {
                Music::instance().reSetMusicTel();
                handleofTelphore(thisObj);
            }
        }
    }
    std::erase_if(m_staticobjects, [](auto& unmovable)
        {
            return unmovable->isDisposed();
        }
    );
}




void ControllerObjects::checkCollisionWithMovingObject(MovingObjects& thisObj, sf::Time deltatime)
{
    for (auto& movable : M_MovingObjects)
    {

        if (thisObj.getObjects() != movable->getObjects())
        {
            if (thisObj.collidesWith(*movable))
            {
                thisObj.handleCollision(*movable);

            }
        }
    }
}


void ControllerObjects::restartTheObjects()
{
    m_staticobjects.clear();
    M_MovingObjects.clear();
    m_gifts.clear();
    wichcharacter = 0;
    King::m_Win = false;
}


void ControllerObjects::giftsSet()
{
  
    sf::Vector2f loc;
    float xLoc, yLoc;
    int width, height, xGifts, yGifts;
    char cGifts;
    width= Board::instance().getWidthMap() - 1;
    height = Board::instance().getHeightMap() - 1;
  
 
    while (m_gifts.size() < maxGifts)
    {
        xGifts = rand() % (width - 2 + 1) + 2;
        yGifts = rand() % (height - 2 + 1) + 2;
        cGifts = Board::instance().getCharMap(yGifts, xGifts);
        while (cGifts != ' ')
        {
            xGifts = rand() % (width- 2 + 1) + 2;
            yGifts = rand() % (height- 2 + 1) + 2;
            cGifts = Board::instance().getCharMap(yGifts, xGifts);
        }
        

     
        xLoc = (P_SIZE * xGifts)+ m_xStart;

        yLoc = (P_SIZE * (yGifts))+ m_yStart;
       

        loc = { xLoc,yLoc };
  
        m_gifts.push_back(Gifts( loc));
      
    }
   

}


void ControllerObjects::handleGifts(MovingObjects& thisObj)
{

    for (size_t i = 0; i < m_gifts.size(); i++)
    {
        if (thisObj.getSprite().getGlobalBounds().intersects(m_gifts[i].getShape().getGlobalBounds()))
        {
            switch (m_gifts[i].getType())
            {
            case gifts::EnTime:
                Toolbar::instance().increastime();
                break;
            case gifts::DECTIME:
                Toolbar::instance().decreastime();
                break;
            case gifts::ERASEO:
                eraseEnemy();
                break;
            }

            
            m_gifts.erase(m_gifts.begin() + i); ///error
            Music::instance().reSetMusicTake();
        }
    }

}

void ControllerObjects::eraseEnemy()
{
    for (auto& movable : M_MovingObjects)
    {

        std::erase_if(M_MovingObjects, [](auto& movable)
            {
                return (movable->getObjects() == EnemyObj);
            });

    }

}

void ControllerObjects::setTelphore()
{
    sf::Vector2f pos;
    int y = 0;
    int temp = 0;
    for (size_t i = 0; i < m_staticobjects.size(); i++)
    {

        if (m_staticobjects[i]->getObjects() == TelObj)
        {
            if (y == 0)
            {
                temp = i;
                pos = m_staticobjects[i]->getSprite().getPosition();
            }
            else {
                size_t index = tekphoretwins(i);

                if (index == i)
                {
                    static_cast<Telphore&>(*m_staticobjects[temp]).setTwins(m_staticobjects[i]->getSprite().getPosition());
                    static_cast<Telphore&>(*m_staticobjects[i]).setTwins(pos);
                    break;
                }
                i = index;
            }
            y++;
        }
    }
}

size_t ControllerObjects::tekphoretwins(size_t i)
{
    
    size_t y = i;
    i++;
    for (; i < m_staticobjects.size(); i++)
    {
        if (m_staticobjects[i]->getObjects() == TelObj)
        {
            static_cast<Telphore&>(*m_staticobjects[y]).setTwins(m_staticobjects[i]->getSprite().getPosition());
            static_cast<Telphore&>(*m_staticobjects[i]).setTwins(m_staticobjects[y]->getSprite().getPosition());
            y = i;
            break;
        }
    }
    return y;
}

void ControllerObjects::handleofTelphore(MovingObjects& thisObj)
{
    for (auto& movable : m_staticobjects)
    {
        if (thisObj.collidesWith(*movable))
        {
            Objects objec_moving = thisObj.getObjects();
            if (objec_moving == WarriorObj)
            {
                thisObj.handleCollision(*movable);
                movable = std::make_unique<Key>(KeyObj, movable->getSprite().getPosition());
            }
            else
            {
                thisObj.handleCollision(*movable);
            }
        }
    }
    std::erase_if(m_staticobjects, [](auto& unmovable)
        {
            return unmovable->isDisposed();
        });
}
