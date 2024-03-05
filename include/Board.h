#pragma once

#include <SFML/Graphics.hpp>
//#include "Matrix.h"
#include "GameObject.h"
#include "Key.h"
#include <memory>
//#include "SuperPresent.h"
//#include "Freeze.h"
//#include "AddLife.h"
//#include "AddTime.h"
#include "Door.h"
#include "Cheese.h"
#include "Wall.h"
#include "Mouse.h"
#include "Cat.h"
#include "Present.h"
#include <fstream>
#include "MovingObject.h"
#include "StaticObjects.h"
#include <vector>
#include <memory>
#include <iostream>



class Board
{
public:
    Board();
    void readboard();

    void drawBoard(sf::RenderWindow& m_window);
    void updateGame(const sf::Time delta_Time);
    sf::Vector2f CalculateFactor();
    sf::Sprite GetGameObjectMoving(const int index);

    int returnMouseLife() const;
    int returnMouseScore() const;
    int returnMouseKeys() const;
    int getCheese() const;
    int getEattenCheese() const;

    



private:

    int m_cheese = 0;
    int m_mouse_idx =0;
    int m_row = 0;
    int m_col = 0;

    std::vector<std::string> m_matrixVector;
    std::ifstream m_ifile;  //= std::ifstream("Board.txt"); // the board
    std::vector<std::unique_ptr<movingObject>> m_MovingObject;
    std::vector<std::unique_ptr<StaticObject>> m_StaticObject;



};