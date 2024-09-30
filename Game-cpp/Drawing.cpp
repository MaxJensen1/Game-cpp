#include "Drawing.h"

void Drawing::DrawGame()
{
    for (int y = 0; y < height; ++y)
    {
        for (int x = 0; x < width; ++x)
        {
            if (gameGrid[y][x] != ' ') // Only draw if the character is not a space
            {
                SetColor(colorGrid[y][x]); // Set color for the current character
                SetCursorPosition(x, y); // Move cursor to the correct position
                std::cout << gameGrid[y][x]; // Output the character
            }
        }
    }
}

void Drawing::AddToDrawQueue(int x, int y, char symbol, ConsoleColor color)
{
    if (x >= 0 && x < width && y >= 0 && y < height) // Makes sure the input coordinates aren't outside of the bounds of the arrays
    {
        gameGrid[y][x] = symbol;
        colorGrid[y][x] = color;
    }
}