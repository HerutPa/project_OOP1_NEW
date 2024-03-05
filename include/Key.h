#pragma once

#include "StaticObjects.h"
#include <SFML/Graphics.hpp>
#include "Mouse.h"
//#include "Deamon.h"

class Key :public StaticObject
{
public:

    Key(sf::Texture Texture, sf::Vector2f Position);
    Key();
    virtual void HandleCollision(Key& obj) {};
    ~Key();
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

};