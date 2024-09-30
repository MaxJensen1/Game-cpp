#pragma once
#include<iostream>
#include "ColorsAndCursor.h"
#include <vector>

class Drawing : public ColorsAndCursor
{
public:
    Drawing(): width(GetConsoleWidth()), height(GetConsoleHeight()), gameGrid(height, std::vector<char>(width, ' ')), colorGrid(height, std::vector<ConsoleColor>(width)) {}

public:
    void DrawGame();
    void AddToDrawQueue(int x, int y, char symbol, ConsoleColor color);

private:
    int width;
    int height;
    std::vector<std::vector<char>> gameGrid;
    std::vector<std::vector<ConsoleColor>> colorGrid;
};