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
    if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) // Check if ESC key is pressed
    {
        std::cout << "Escape key pressed, exiting...\n";
        exit(0);
    }
}

void Player::MoveLeft()
{
    if (x >= 4)
    {
        x -= 2;
    }
}

void Player::MoveRight()
{
    if (x <= ScreenWidth() - 4)
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
    if (y <= ScreenHeight() - 4)
    {
        y += 1;
    }
}

void Player::Draw()
{
    // Draw top part of the ship in blue
    SetColor(1);
    SetCursorPosition(x - 3, y - 2);
    std::cout << " / \\" << std::endl;

    // Draw middle part of the ship in white
    SetColor(7);
    SetCursorPosition(x - 3, y - 1);
    std::cout << " |o|" << std::endl;

    // Draw bottom part of the ship in blue
    SetColor(1);
    SetCursorPosition(x - 3, y);
    std::cout << "/_ _\\" << std::endl;

    // Draw thrusters in red
    SetColor(4);
    SetCursorPosition(x - 3, y + 1);
    std::cout << " ^ ^" << std::endl;
}

//bool Player::IsCollision(Asteroid* asteroid)
//{
//    // Collision box for top, middle, and bottom part of the ship
//    int toleranceTop = 1;
//    int toleranceMiddle = 1;
//    int toleranceBottom = 2;
//
//    // Adjust the X coordinates in the collision checks to make the collision box wider
//    bool topCollision = abs(x + 1 - asteroid->x) <= toleranceTop && y == asteroid->y; // Checks only the y-level it's on
//    bool middleCollision = abs(x + 1 - asteroid->x) <= toleranceMiddle && abs(y - asteroid->y) <= 1; // Checks its y-level and the one above
//    bool bottomCollision = abs(x + 1 - asteroid->x) <= toleranceBottom && abs(y - asteroid->y) <= 2; // Checks two y'levels above
//
//    return topCollision || middleCollision || bottomCollision; // If one is true, it returns true. If all are false it returns false
//}