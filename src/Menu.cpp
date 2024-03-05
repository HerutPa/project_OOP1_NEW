#pragma once

#include "Menu.h"

Menu::Menu(int width, int height)
	:m_WINDOW_WIDTH(width), m_WINDOW_HEIGHT(height)
{
	
	//define the arrays:
	for (int button = PLAY; button <= BACK; button++)
	{
		m_Buttons[button].setTexture(Resources::instance().GetButton((Button)button));
	}

	for (int title = TITLE; title <= TITLE/*בכוונה נתתי לו לרוץ פעם אחת וגם במנוע המרכזי שיניתי ככה*/; title++)
	{
		m_TitleObjects[title].setTexture(Resources::instance().GetTitle((Title)title));
	}

	for (int instruction = GAME_RULES; instruction <= GAME_RULES; instruction++)
	{
		m_Instructions_Page[instruction].setTexture(Resources::instance().GetInstruction((Instructions)instruction));
	}




	

	/*for (int instruction = SHIR; instruction <= GAME_RULES; instruction++)
	{
		m_Instructions_Page[instruction].setTexture(Resources::instance().GetInstruction((Instructions)instruction));
	}*/

	//m_Sound[CLICK].setBuffer(Resources::instance().GetSound(CLICK));

	////define the first visibility
	//m_TitleObjects[HELLO].setColor(sf::Color::Color(255, 255, 255, 0));
	//m_TitleObjects[WANNA_PLAY].setColor(sf::Color::Color(255, 255, 255, 0));
	//m_TitleObjects[LETS_GO].setColor(sf::Color::Color(255, 255, 255, 0));
	//m_TitleObjects[TITLE_PACMAN].setColor(sf::Color::Color(255, 255, 255, 0));
	//m_TitleObjects[TITLE_DEAMONS].setColor(sf::Color::Color(255, 255, 255, 0));
	//m_Instructions_Page[SHIR].setColor(sf::Color::Color(255, 255, 255, 0));
	//m_Instructions_Page[EVIATAR2].setColor(sf::Color::Color(255, 255, 255, 0));
	//m_Instructions_Page[SHIR_DROP].setColor(sf::Color::Color(255, 255, 255, 0));
	//m_Instructions_Page[EVIATAR_DROP].setColor(sf::Color::Color(255, 255, 255, 0));
	m_Instructions_Page[GAME_RULES].setColor(sf::Color::Color(255, 255, 255, 0));
	
	SetPosition();
}


void Menu::SetPosition()
{
	//resize:
	//Buttons:
	m_Buttons[PLAY].scale(sf::Vector2f(m_WINDOW_WIDTH * 0.195 / m_Buttons[PLAY].getTextureRect().width,
		m_WINDOW_WIDTH * 0.195 / m_Buttons[PLAY].getTextureRect().width));

	m_Buttons[HELP].scale(sf::Vector2f(m_WINDOW_WIDTH * 0.195 / m_Buttons[HELP].getTextureRect().width,
		m_WINDOW_WIDTH * 0.195 / m_Buttons[HELP].getTextureRect().width));

	m_Buttons[EXIT].scale(sf::Vector2f(m_WINDOW_WIDTH * 0.195 / m_Buttons[EXIT].getTextureRect().width,
		m_WINDOW_WIDTH * 0.195 / m_Buttons[EXIT].getTextureRect().width));

	m_Buttons[BACK].scale(sf::Vector2f(m_WINDOW_WIDTH * 0.12 / m_Buttons[BACK].getTextureRect().width,
		m_WINDOW_WIDTH * 0.12 / m_Buttons[BACK].getTextureRect().width));

	m_Buttons[VIDEO_PLAY].scale(sf::Vector2f(m_WINDOW_WIDTH * 0.05 / m_Buttons[VIDEO_PLAY].getTextureRect().width,
		m_WINDOW_WIDTH * 0.05 / m_Buttons[VIDEO_PLAY].getTextureRect().width));

	//Title:
	m_TitleObjects[TITLE].scale(sf::Vector2f(m_WINDOW_WIDTH * 0.5 / m_TitleObjects[TITLE].getTextureRect().width,
		m_WINDOW_WIDTH * 0.5 / m_TitleObjects[TITLE].getTextureRect().width));

	//Instructions:

	m_Instructions_Page[GAME_RULES].scale(sf::Vector2f(m_WINDOW_WIDTH * 0.65 / m_Instructions_Page[GAME_RULES].getTextureRect().width,
		m_WINDOW_WIDTH * 0.65 / m_Instructions_Page[GAME_RULES].getTextureRect().width));




	//locate: //כל מה שכאן צריך להיות קשור למיקום
//Buttons
	m_Buttons[PLAY].setPosition(sf::Vector2f((m_WINDOW_WIDTH - m_Buttons[PLAY].getTextureRect().width) * 0.5,
		m_WINDOW_HEIGHT - m_Buttons[PLAY].getTextureRect().height * 1.5 * 3));

	m_Buttons[HELP].setPosition(sf::Vector2f((m_WINDOW_WIDTH - m_Buttons[HELP].getTextureRect().width) * 0.5,
		m_WINDOW_HEIGHT - m_Buttons[HELP].getTextureRect().height * 1.5 * 2));

	m_Buttons[EXIT].setPosition(sf::Vector2f((m_WINDOW_WIDTH - m_Buttons[EXIT].getTextureRect().width) * 0.5,
		m_WINDOW_HEIGHT - m_Buttons[EXIT].getTextureRect().height * 1.5 * 1));

	m_Buttons[VIDEO_PLAY].setPosition(sf::Vector2f(m_WINDOW_WIDTH * 0.88, m_WINDOW_HEIGHT * 0.73));

	m_Buttons[BACK].setPosition(sf::Vector2f(m_WINDOW_WIDTH * 0.85, m_WINDOW_HEIGHT * 0.85));

	//Title
	m_TitleObjects[TITLE].setPosition(sf::Vector2f(m_WINDOW_WIDTH * 0.25, m_WINDOW_HEIGHT * 0.1));


	//Instructions:

	m_Instructions_Page[GAME_RULES].setPosition(sf::Vector2f(m_WINDOW_WIDTH * 0.15, m_WINDOW_HEIGHT * 0.0));

}


sf::Sprite Menu::GetButton(const Button object) const
{
	return m_Buttons[object];
}

sf::Sprite Menu::GetTitle(const Title object) const
{
	return m_TitleObjects[object];
}
void Menu::ButtonRelease(const Button button)
{
	m_Buttons[button].setColor(sf::Color::Color(255, 255, 255));
}

void Menu::ButtonPress(const Button button)
{
	m_Buttons[button].setColor(sf::Color::Color(255, 255, 255, 150));
}

sf::Sprite Menu::GetInstructions(const Instructions object) const
{
	return m_Instructions_Page[object];
}

//void Menu::PlaySound(const Sound sound)
//{
//	m_Sound[sound].play();
//}