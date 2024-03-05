#pragma once

#include "Resources.h"

Resources::Resources()
{
	loadTextures();
}

//loading all images
void Resources::loadTextures()
{
	m_textureVec.resize(TextureObject::t_Total);
	m_textureVec[TextureObject::t_wall].loadFromFile("wall.png");
	m_textureVec[TextureObject::t_door].loadFromFile("door.png");
	m_textureVec[TextureObject::t_cat].loadFromFile("cat.png");
	m_textureVec[TextureObject::t_mouse].loadFromFile("mouse.png");
	m_textureVec[TextureObject::t_cheese].loadFromFile("cheese.png");
	m_textureVec[TextureObject::t_present].loadFromFile("present.png");
	m_textureVec[TextureObject::t_key].loadFromFile("key.png");
	//m_textureVec[TextureObject::t_save].loadFromFile("save.png");
	//m_textureVec[TextureObject::t_reset].loadFromFile("reset.png");

	for (int button = PLAY; button <= BACK; button++)
	{
		m_ButtonTextures[button].loadFromFile(m_ButtonFiles[button]);
		m_ButtonTextures[button].setSmooth(true);
	}

	for (int instruction = GAME_RULES; instruction <= GAME_RULES; instruction++)
	{
		m_InstructionsTextures[instruction].loadFromFile(m_InstructionFiles[instruction]);
		m_InstructionsTextures[instruction].setSmooth(true);
	}

	/*for (int sound = SONG; sound <= GAME_OVER; sound++)
	{
		m_Sounds[sound].loadFromFile(m_SoundFiles[sound]);
	}*/
	m_font.loadFromFile("C:/Windows/Fonts/Arial.ttf");
}

Resources::~Resources()
{
}

Resources& Resources::instance()
{
	static Resources Resource;
	return Resource;
}

const sf::Texture& Resources::getTexture(TextureObject texObj) const
{
	return m_textureVec[texObj];
}

const sf::Font& Resources::getFont() const
{
	return m_font;
}

sf::Texture& Resources::GetButton(Button button)
{
	return m_ButtonTextures[button];
}

sf::Texture& Resources::GetTitle(Title title)
{
	return m_TitleTextures[title];
}

sf::Texture& Resources::GetInstruction(Instructions instruction)
{
	return m_InstructionsTextures[instruction];
}

//sf::SoundBuffer& Resources::GetSound(Sound sound)
//{
//	return m_Sounds[sound];
//}