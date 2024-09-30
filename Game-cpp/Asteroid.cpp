#include "Asteroid.h"

void Asteroid::Draw()
{
	SetColor(RED);
	SetCursorPosition(x, y);
	std::cout << "O\n";
	
	SetColor(YELLOW);
	SetCursorPosition(x, y - 1);
	std::cout << "|\n";
}

bool Asteroid::Fall(int fallSpeed)
{
	if (y <= GetConsoleHeight() - 4)
	{
		y += fallSpeed;
		return false;
	}
	else
	{
		return true;
	}
}
