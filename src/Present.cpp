#include "Present.h"

Present::Present(sf::Texture Texture, sf::Vector2f Position) : StaticObject(Texture, Position)
{
	m_sprite.setTexture(Resources::instance().getTexture(Resources::t_present));
	m_char = '$';
}

Present::~Present()
{
}

void Present::HandleCollision(Mouse& mouse)
{
	m_isCollide = true;
	mouse.HandleCollision(*this);

}
