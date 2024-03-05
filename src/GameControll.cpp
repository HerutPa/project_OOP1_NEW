#pragma once
#include <iostream>
#include "GameControll.h"

GameControll::GameControll()
    :m_window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Mouse&Cat"),
        m_menu(WINDOW_WIDTH, WINDOW_HEIGHT),

    m_board()
{
    m_background.loadFromFile("background.png");
    m_backgroundplay.loadFromFile("backgroundplay.png");
    m_background.setSmooth(true);
    m_backgroundplay.setSmooth(true);
    sf::Sprite s1(m_background);
    sf::Sprite s2(m_backgroundplay);
    s1.scale(sf::Vector2f(1.2f, 1.2f));
    s2.scale(sf::Vector2f(1.2f, 1.2f));
    m_window.clear(sf::Color::Color(0, 0, 0));
    m_window.draw(s1);
    m_window.display();
    m_window.setFramerateLimit(60);
    //m_Sound[0].setBuffer(m_resource.GetSound(SONG));
    //m_Sound[1].setBuffer(m_resource.GetSound(GAME_OVER));
}

void GameControll::run()
{
    while (m_window.isOpen())
    {
        sf::Sprite s1(m_background);
        s1.scale(sf::Vector2f(2.35f, 1.35f));
        m_window.clear(sf::Color::Color(0, 0, 0));
        m_window.draw(s1);
        DrawMenu();
        m_window.display();

        if (auto event = sf::Event{}; m_window.waitEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                m_window.close();
                break;

            case sf::Event::MouseButtonReleased:
            {
                auto location = m_window.mapPixelToCoords(
                    { event.mouseButton.x, event.mouseButton.y });
                handleClick(location);
                break;
            }

            case sf::Event::MouseMoved:
            {
                auto location = m_window.mapPixelToCoords(sf::Mouse::getPosition(m_window));
                handleMouseMoved(location, PLAY, EXIT);
            }
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            m_window.close();
        }
    }
}


void GameControll::handleMouseMoved(const sf::Vector2f location, const Button first, const Button last)
{
    for (int button = first; button <= last; button++)
    {
        if ((m_menu.GetButton((Button)button).getGlobalBounds().contains(location)))
        {
            m_menu.ButtonPress((Button)button);
        }
        else
        {
            m_menu.ButtonRelease((Button)button);
        }
    }
}


void GameControll::DrawMenu()
{
    for (int object = TITLE; object <= TITLE_DEAMONS; ++object)
    {
        m_window.draw(m_menu.GetTitle((Title)object));
    }

    for (int button = PLAY; button <= EXIT; ++button)
    {
        m_window.draw(m_menu.GetButton((Button)button));
    }
}

void GameControll::handleClick(const sf::Vector2f& location)
{
    if (m_menu.GetButton(PLAY).getGlobalBounds().contains(location))
    {
       //m_menu.PlaySound(CLICK);
       //m_Sound[0].play();
        //PlayVideo();
        StartGame();
    }
    else if (m_menu.GetButton(HELP).getGlobalBounds().contains(location))
    {
       // m_menu.PlaySound(CLICK);
       InstructionsLoop();
    }
    else if (m_menu.GetButton(EXIT).getGlobalBounds().contains(location))
    {
        //m_menu.PlaySound(CLICK);
        m_window.close();
    }
}

void GameControll::InstructionsLoop()
{
    bool exit = false;
    while (!exit)
    {
        m_window.clear(sf::Color::Color(0, 0, 0));
        DrawInstructions();
        m_window.display();

        if (auto event = sf::Event{}; m_window.waitEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                exit = true;
                m_window.close();
                break;

            /*case sf::Event::MouseButtonReleased:
            {
                auto location = m_window.mapPixelToCoords(
                    { event.mouseButton.x, event.mouseButton.y });
                handleNextClick(location, exit);
                break;
            }*/

            case sf::Event::MouseMoved:
            {
                auto location = m_window.mapPixelToCoords(sf::Mouse::getPosition(m_window));
                handleMouseMoved(location, VIDEO_PLAY, BACK);
            }

            }
        }
    }
}

void GameControll::StartGame()
{

    m_board.readboard();

    while (m_window.isOpen())
    {
        sf::Sprite s2(m_backgroundplay);
        s2.scale(sf::Vector2f(2.35f, 1.35f));
        DrawMenu();

        m_window.clear(sf::Color::Color(0, 102, 102));
        m_window.draw(s2);

        m_board.drawBoard(m_window);
        drawToolBar();
        m_window.display();

        for (auto event = sf::Event{}; m_window.pollEvent(event); )
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                m_window.close();
                break;
            }
        }
        auto delta_Time = m_MoveClock.restart();
        m_board.updateGame(delta_Time); //update moving directions
        //m_board.UpdateMoving(m_AddedTime); // update moving objects below the situation
        UpdateData();

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            m_window.close();
        }

        if (m_board.returnMouseLife() == 0) //lose
        {
            //m_Sound[1].play();
            m_level = 0;
            break;
        }

        else if (m_board.getCheese() - m_board.getEattenCheese() == 0) // next level
        {
            /*if (m_board.ReadNewLevel())
            {
                m_board.setMouseData(m_toolbar.GetLife(), m_toolbar.GetScore());
                m_level++;
                m_GameClock.restart();
            }*/
            //else // end of the game
            //{
            //    m_level = 0;
            //    break;
            //}
        }
        //else if (m_GameClock.getElapsedTime().asSeconds() > 120 + m_AddedTime) // time over
        //{
        //    m_board.InitLevel();
        //    m_GameClock.restart();
        //}
    }   
 }

void GameControll::drawToolBar()
{
    for (int word = LIFE; word <= KEYCOUNTER; word++)
    {
        m_window.draw(m_toolbar.GetText(word));
        m_window.draw(m_toolbar.GetNum(word));
    }
}

void GameControll::UpdateData()
{
    //update the toolbar data
    m_toolbar.setLife(m_board.returnMouseLife());
    m_toolbar.SetScore(m_board.returnMouseScore());
    m_toolbar.SetLevel(m_level);
    m_toolbar.SetKeys(m_board.returnMouseKeys());
    //m_toolbar.SetTime(m_GameClock.getElapsedTime().asSeconds() - m_AddedTime);
}




void GameControll::DrawInstructions()
{
    for (int object = GAME_RULES; object <= GAME_RULES; ++object)
    {
        m_window.draw(m_menu.GetInstructions((Instructions)object));
    }
    for (int object = VIDEO_PLAY; object <= BACK; ++object)
    {
        m_window.draw(m_menu.GetButton((Button)object));
    }
}
