#include "MovingObject.h"

movingObject::movingObject(sf::Texture Texture, sf::Vector2f Position)
    :GameObject(Texture,Position)
{}

movingObject::~movingObject()
{
}

void movingObject::setOriginalPos(sf::Vector2f Position)
{
    m_originalPos = Position;
}

const sf::Vector2f movingObject::getOriginalPos()
{
    return m_originalPos;
}

sf::Vector2f movingObject::directionToVector(sf::Keyboard::Key key)
{
    switch (key)
    {
    case sf::Keyboard::Up:
        return { 0, -1 };
    case sf::Keyboard::Down:
        return { 0, 1 };
    case sf::Keyboard::Right:
        return { 1, 0 };
    case sf::Keyboard::Left:
        return { -1, 0 };
    default:
        return { 0, 0 };
    }
}