#include "Cat.h"

constexpr auto CatSize = 400.f;
constexpr auto CatSpeed = CatSize * 1;

Cat::Cat(sf::Texture Texture, sf::Vector2f Position) : movingObject(Texture, Position)
{
	m_sprite.setTexture(Resources::instance().getTexture(Resources::t_cat));
	m_char = '^';
	/*: m_keyBoard({ sf::Keyboard::Up, sf::Keyboard::Right, sf::Keyboard::Down, sf::Keyboard::Left })*/
	/*m_keyBoard.push_back(sf::Keyboard::Up);
	m_keyBoard.push_back(sf::Keyboard::Down);
	m_keyBoard.push_back(sf::Keyboard::Left);
	m_keyBoard.push_back(sf::Keyboard::Right);*/
}



Cat::~Cat()
{

}

void Cat::moveObject(sf::Time clock)
{
	sf::Vector2f direction = directionToVector(getKeyPress());
	m_stapSize = CatSpeed * direction * clock.asSeconds();
	m_sprite.move(m_stapSize);
}

sf::Keyboard::Key Cat::getKeyPress() const
{
	for (int i = 0; i < m_keyBoard.size(); i++) //checking which arrow key is pressed and returning it
	{
		if (sf::Keyboard::isKeyPressed(m_keyBoard[i]))
			return m_keyBoard[i];
	}

	return sf::Keyboard::Key();

}


void Cat::updateMovement(sf::Vector2f, int)
{
}

void Cat::checkCollition(std::vector<std::unique_ptr<movingObject>> &m_MovingObject, std::vector<std::unique_ptr<StaticObject>> &m_StaticObject)
{
}

void Cat::UpdateDirection(sf::Vector2f)
{
}