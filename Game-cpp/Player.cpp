#include "Player.h"

void Player::HandleInputs()
{
    // Check if specific keys are pressed
    if (GetAsyncKeyState('W') & 0x8000) // Check if 'W' is pressed
    {
        MoveUp();
    }
    if (GetAsyncKeyState('A') & 0x8000) // Check if 'A' is pressed
    {
        MoveLeft();
    }
    if (GetAsyncKeyState('S') & 0x8000) // Check if 'S' is pressed
    {
        MoveDown();
    }
    if (GetAsyncKeyState('D') & 0x8000) // Check if 'D' is pressed
    {
        MoveRight();
    }
}

void Player::MoveLeft()
{
    if (x >= 5)
    {
        x -= 2;
    }
}

void Player::MoveRight()
{
    if (x <= GetConsoleWidth() - 4)
    {
        x += 2;
    }
}

void Player::MoveUp()
{
    if (y >= 3)
    {
        y -= 1;
    }
}

void Player::MoveDown()
{
    if (y <= GetConsoleHeight() - 4)
    {
        y += 1;
    }
}

void Player::Draw()
{
    // Draw top part of the ship in blue
    SetColor(BLUE);
    SetCursorPosition(x - 3, y - 2);
    std::cout << " / \\" << std::endl;

    // Draw middle part of the ship in white
    SetColor(WHITE);
    SetCursorPosition(x - 3, y - 1);
    std::cout << " |o|" << std::endl;

    // Draw bottom part of the ship in blue
    SetColor(BLUE);
    SetCursorPosition(x - 3, y);
    std::cout << "/_ _\\" << std::endl;

    // Draw thrusters in red
    SetColor(RED);
    SetCursorPosition(x - 3, y + 1);
    std::cout << " ^ ^" << std::endl;
}

void Player::SetDefaultPos()
{
    x = GetConsoleWidth() / 2;
    y = GetConsoleHeight() - 3;
}

bool Player::IsCollision(std::vector<Asteroid*> asteroids)
{
    for (auto asteroid : asteroids)
    {
        // Collision box for top, middle, and bottom part of the ship
        int toleranceTop = 1;
        int toleranceMiddle = 1;
        int toleranceBottom = 2;

        // Adjust the X coordinates in the collision checks to make the collision box wider
        bool topCollision = abs(x - 1 - asteroid->x) <= toleranceTop && y - 2 == asteroid->y; // Checks only the y-level it's on
        bool middleCollision = abs(x - 1 - asteroid->x) <= toleranceMiddle && abs(y - asteroid->y) == 1;
        bool bottomCollision = abs(x - 1 - asteroid->x) <= toleranceBottom && abs(y - asteroid->y) <= 0;

        if (topCollision || middleCollision || bottomCollision) // If a collision is detected, return true
        {
            return true;
        }
    }

    return false; // If no collision is detected after checking all asteroids, return false
}