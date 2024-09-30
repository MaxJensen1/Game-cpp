#pragma once
#include <iostream>
#include <Windows.h>
#include "Game.h"

void SetNewConsoleSize(int, int);

int main()
{
    SetNewConsoleSize(50, 35);

    Game game;
	game.Run();
}

void SetNewConsoleSize(int width, int height) 
{
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD size; // Has an x and y coordinate (width and height)

    size.X = width;
    size.Y = height;

    SetConsoleScreenBufferSize(consoleHandle, size);

    SMALL_RECT windowSize = { 0, 0, width - 1, height - 1 };
    SetConsoleWindowInfo(consoleHandle, TRUE, &windowSize);
}