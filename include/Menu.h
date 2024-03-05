#pragma once

#include <SFML/Graphics.hpp>
//#include <SFML/Audio.hpp>
#include "Resources.h"


class Menu
{
public:
	Menu(int, int);

	sf::Sprite GetButton(const Button) const;
	sf::Sprite GetTitle(const Title object) const;
	void ButtonRelease(const Button button);
	void ButtonPress(const Button button);
	sf::Sprite GetInstructions(const Instructions) const;
	//void PlaySound(const Sound sound);

private:

	//members
	const int m_WINDOW_HEIGHT;
	const int m_WINDOW_WIDTH;

	//arrays
	sf::Sprite m_Buttons[BUTTONS];
	sf::Sprite m_TitleObjects[TITLE_OBJECTS];
	sf::Sprite m_Instructions_Page[INSTRUCTIONS];
//	sf::Sound m_Sound[SOUNDS];

	void SetPosition();

};
