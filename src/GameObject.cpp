#include "GameObject.h"


GameObject::GameObject()
{
}

GameObject::GameObject(sf::Texture Texture, sf::Vector2f Position)
	:m_sprite(Texture)
{
	m_sprite.setPosition(Position);
	m_char = ' ';
}

void GameObject::drawObject(sf::RenderWindow& m_window)
{
	m_window.draw(m_sprite);
}

void GameObject::satScale(sf::Vector2f scale)
{
	m_sprite.setScale(scale);
}

const sf::Vector2f  GameObject::getPosition()
{
	return m_sprite.getPosition();
}

const char GameObject::getChar()
{
	return m_char;
}

//כדי לדעת האם שני עצמים התנגשו בהמשך
sf::FloatRect GameObject::getBounds()
{
	return m_sprite.getGlobalBounds();
}

void GameObject::HandleCollision(GameObject& obj)
{
	obj.HandleCollision(*this);
}

void GameObject::HandleCollision(Key& obj)
{

}

sf::Sprite& GameObject::GetSprite()
{
	return m_sprite;
}

const bool GameObject::getIsCollide() const
{
	return m_isCollide;
}

