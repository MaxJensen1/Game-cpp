#include "Player.h"
#include <conio.h>

void Player::HandleInputs()
{
    if (_kbhit()) {  // Check if a key has been pressed
        char ch = _getch();  // Get the character of the key
        switch (ch) 
        {
        case 'w':
            std::cout << "You pressed 'w'\n";
            MoveUp();
            break;
        case 'a':
            std::cout << "You pressed 'a'\n";
            MoveLeft();
            break;
        case 's':
            std::cout << "You pressed 's'\n";
            MoveDown();
            break;
        case 'd':
            std::cout << "You pressed 'd'\n";
            MoveRight();
            break;
        case 27:  // ASCII value for ESC key
            std::cout << "Escape key pressed, exiting...\n";
            exit(0);
            return;

        default:
            break;
        }
    }
}

void Player::MoveLeft()
{
    x -= 1;
}

void Player::MoveRight()
{
    x += 1;
}

void Player::MoveUp()
{
    x -= 1;
}

void Player::MoveDown()
{
    x += 1;
}

void Player::Draw()
{
    // Draw top part of the ship in blue
    SetColor(1);
    SetCursorPosition(x - 3, y - 2);
    std::cout << " / \\\n";

    // Draw middle part of the ship in white
    SetColor(7);
    SetCursorPosition(x - 3, y - 2);
    std::cout << " |o|\n";

    // Draw bottom part of the ship in blue
    SetColor(1);
    SetCursorPosition(x - 3, y - 2);
    std::cout << "/_ _\\\n";

    // Draw thrusters in red
    SetColor(4);
    SetCursorPosition(x - 3, y - 2);
    std::cout << " ^ ^\n";
}
