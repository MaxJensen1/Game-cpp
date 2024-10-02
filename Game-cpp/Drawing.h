#pragma once
#include<iostream>
#include "ConsoleGraphics.h"
#include <vector>

class Drawing : public ConsoleGraphics
{
public:
    Drawing(): width(GetConsoleWidth()), height(GetConsoleHeight()), gameGrid(height, std::vector<char>(width, ' ')), colorGrid(height, std::vector<ConsoleColor>(width)), prevGameGrid(height, std::vector<char>(width, ' ')) {}

public:
    void AddToDrawQueue(int x, int y, char symbol, ConsoleColor color);
    void DrawGame(); // Draws everything in the arrays
    void ClearQueue();

private:
    int width;
    int height;

    std::vector<std::vector<char>> gameGrid;
    std::vector<std::vector<char>> prevGameGrid;
    std::vector<std::vector<ConsoleColor>> colorGrid;
};