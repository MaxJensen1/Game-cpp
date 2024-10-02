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
                SetCursorPosition(x, y); // Move cursor to (x, y)
                std::cout << gameGrid[y][x]; // Print the character
            }
        }
    }
}

void Drawing::ClearQueue()
{
    for (int y = 0; y < height; ++y)
    {
        for (int x = 0; x < width; ++x)
        {
            // Set any non-empty cell to empty
            if (prevGameGrid[y][x] != ' ')
            {
                gameGrid[y][x] = ' '; // Clear the cell in gameGrid
                //colorGrid[y][x] = WHITE;
                SetCursorPosition(x, y); // Draw empty on cells that aren't empty, to clear the console
                std::cout << ' ';
            }
        }
    }
}

void Drawing::AddToDrawQueue(int x, int y, char symbol, ConsoleColor color)
{
    prevGameGrid = gameGrid; // Keep track of gameGrid before it's updated

    if (x >= 0 && x < width && y >= 0 && y < height) // Makes sure the input coordinates aren't outside of the bounds of the arrays
    {
        gameGrid[y][x] = symbol;
        colorGrid[y][x] = color;
    }
}