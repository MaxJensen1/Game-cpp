#include "Difficulty.h"

void Difficulty::IncreaseDifficulty()
{
    difficulty++;

    //Change game speed and asteroid spawn amount
    switch (difficulty)
    {
    case 2: asteroidSpawnAmount = 12;
        break;

    case 3:asteroidSpawnAmount = 14;
        break;

    case 4: asteroidSpawnAmount = 16;
        break;

    case 5: asteroidSpawnAmount = 18;
        break;

    case 6: asteroidSpawnAmount = 20;
        break;

    case 7: asteroidSpawnAmount = 22;
        break;

    case 8: asteroidSpawnAmount = 24;
        break;

    case 9: asteroidSpawnAmount = 26;
        break;

    case 10: asteroidSpawnAmount = 28;
        break;
    }

    if (difficulty > 10)
    {
        asteroidSpawnAmount += 10;
    }
}

void Difficulty::DifficultyText(bool displayText)
{
    // Retrieve console buffer info
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);

    int width = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    int height = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

    std::string message = "Difficulty Increase: Level " + std::to_string(difficulty);
    if (!displayText) 
    {
        message = "                                     ";
    }
    int left = (width - message.length()) / 2;
    int top = height / 2;

    SetCursorPosition(left, top);
    std::cout << message << std::endl;
}