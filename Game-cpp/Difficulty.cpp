#include "Difficulty.h"

void Difficulty::IncreaseDifficulty()
{
    difficulty++;

    //Print the text saying that the difficulty is increasing
    DifficultyText();

    //Change game speed and asteroid spawn amount
    switch (difficulty)
    {
    case 2: asteroidSpawnAmount = 12;
        break;

    case 3:asteroidSpawnAmount = 15;
        break;

    case 4: asteroidSpawnAmount = 18;
        break;

    case 5: asteroidSpawnAmount = 10; gameUpdateTime = 50;
        break;

    case 6: asteroidSpawnAmount = 12; gameUpdateTime = 50;
        break;

    case 7: asteroidSpawnAmount = 15; gameUpdateTime = 50;
        break;

    case 8: asteroidSpawnAmount = 18; gameUpdateTime = 50;
        break;

    case 9: asteroidSpawnAmount = 21; gameUpdateTime = 50;
        break;

    case 10: asteroidSpawnAmount = 15; gameUpdateTime = 40;
        break;
    }

    if (difficulty > 10)
    {
        asteroidSpawnAmount = 15 + 3 * (difficulty - 10);
        gameUpdateTime = 40;
        asteroidSpawnAmount += 10;
    }
}

void Difficulty::DifficultyText()
{
    // Retrieve console buffer info
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);

    int width = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    int height = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

    std::string message = "Difficulty Increase: Level " + difficulty;
    int left = (width - message.length()) / 2;
    int top = height / 2;

    SetCursorPosition(left, top);
    std::cout << message << std::endl;
}
