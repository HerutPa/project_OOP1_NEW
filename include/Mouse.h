#pragma once

#include "MovingObject.h"
#include "StaticObjects.h"
#include <SFML/Graphics.hpp>
//#include "Key.h"
//#include "Deamon.h"

class Mouse :public movingObject
{
public:

    Mouse(sf::Texture Texture, sf::Vector2f Position);
    ~Mouse();
    virtual void moveObject(sf::Time clock/*לשלוח שני וקטורים*/);
    virtual void updateMovement(sf::Vector2f, int) ;
    virtual void UpdateDirection(sf::Vector2f) ;

    virtual void checkCollition(std::vector<std::unique_ptr<movingObject>>& m_MovingObject,
                                std::vector<std::unique_ptr<StaticObject>>& m_StaticObject) ;

    virtual void HandleCollision(Mouse& obj) {};
    virtual void HandleCollision(Wall& wall) ;
    virtual void HandleCollision(Cheese& cheese);
    virtual void HandleCollision(Cat& obj) {};
    virtual void HandleCollision(Door& door) ;
    virtual void HandleCollision(Key& key);
    virtual void HandleCollision(Present& present);

    bool haveKey();
    void setLife();
    int getLife();
    int getScore();
    int getKeys();
    int getEatten();




private:
    //Direction m_direction = Stay;
   //sf::Keyboard::Key getKeyMouse();

    std::vector<sf::Keyboard::Key> m_keyBoard;
    sf::Keyboard::Key getKeyPress() const;

    int m_counterKey = 0;
    int m_life = 3;
    int m_score = 0;
    int m_EattenCheese = 0;
    int m_time_collected = 0;

};