#include "Wall.h"
//#include <iostream>

Wall::Wall(sf::Texture Texture, sf::Vector2f Position) : StaticObject(Texture, Position)
{
	m_sprite.setTexture(Resources::instance().getTexture(Resources::t_wall));
	m_char = '#';
}

Wall::~Wall()
{
}

void Wall::HandleCollision(Mouse& obj)
{
	obj.HandleCollision(*this);
}
