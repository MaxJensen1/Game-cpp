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
            break;
        case 'a':
            std::cout << "You pressed 'a'\n";
            break;
        case 's':
            std::cout << "You pressed 's'\n";
            break;
        case 'd':
            std::cout << "You pressed 'd'\n";
            break;
        case 27:  // ASCII value for ESC key
            std::cout << "Escape key pressed, exiting...\n";
            exit(0);
            return;
        default:
            std::cout << "Unknown key: " << ch << '\n';
            break;
        }
    }
}

void Player::MoveLeft()
{
}

void Player::MoveRight()
{
}

void Player::MoveUp()
{
}

void Player::MoveDown()
{
}

void Player::Draw()
{
}
