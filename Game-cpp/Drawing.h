#pragma once
#include <iostream>
#include "ConsoleGraphics.h"
#include <vector>
#include <cstdint>

class Drawing : public ConsoleGraphics
{
public:
    Drawing(): width(GetConsoleWidth()), height(GetConsoleHeight()), gameGrid(height, std::vector<char>(width, ' ')), 
        colorGrid(height, std::vector<ConsoleColor>(width)), prevGameGrid(height, std::vector<char>(width, ' ')) {}

public:
    void AddToDrawQueue(int16_t x, int16_t y, char symbol, ConsoleColor color);
    void DrawGame(); // Draws everything in the arrays
    void ClearQueue();

private:
    uint16_t width;
    uint16_t height;

    std::vector<std::vector<char>> gameGrid;
    std::vector<std::vector<char>> prevGameGrid;
    std::vector<std::vector<ConsoleColor>> colorGrid;
};