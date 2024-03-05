#pragma once

#include "StaticObjects.h"
#include <SFML/Graphics.hpp>
#include "Mouse.h"
//#include "Key.h"

//#include "Pacman.h"
//#include "Deamon.h"

class Door :public StaticObject
{
public:

    Door(sf::Texture Texture, sf::Vector2f Position);
    virtual void HandleCollision(Door& obj) {};
    ~Door();

    virtual void HandleCollision(Mouse& mouse);



	
    /*virtual void HandleCollision(GameObject&)override;
    virtual void HandleCollision(Pacman&)override;
    virtual void HandleCollision(Deamon&)override;
    virtual void HandleCollision(Wall&)override;
    virtual void HandleCollision(Door&)override;
    virtual void HandleCollision(Key&)override;
    virtual void HandleCollision(SuperPresent&)override;
    virtual void HandleCollision(AddTime&)override;
    virtual void HandleCollision(Freeze&)override;
    virtual void HandleCollision(AddLife&)override;
    virtual void HandleCollision(Cookie&)override;*/

    //void SetCollide();

private:

   // Mouse m_mouse;



};