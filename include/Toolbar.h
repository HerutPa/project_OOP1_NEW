#pragma once

#include <SFML/Graphics/Text.hpp>
#include "Resources.h"
#include <string>

class ToolBar
{
public:
	ToolBar();
	sf::Text& GetText(int);
	sf::Text& GetNum(int);
	void setLife(const int);
	void SetScore(const int);
	void SetLevel(const int);
	void SetKeys(const int);
	void SetTime(const int);
	int GetScore();
	int GetLife();
	//void drawToolBar(sf::RenderWindow& m_window);
	//void UpdateData




private:
	//members:
	sf::Text m_toolbar[TOOL_BAR];
	sf::Text m_Info[TOOL_BAR];
	std::string m_Words[TOOL_BAR] = { "Life:" , "Score:", "Level:", "Time:" ,"Keys:" };
	int m_info_num[TOOL_BAR];

};