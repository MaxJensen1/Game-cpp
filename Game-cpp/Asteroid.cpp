#include "Asteroid.h"

void Asteroid::Draw()
{
	SetColor(4);
	SetCursorPosition(x, y);
	std::cout << "O\n";
	
	SetColor(6);
	SetCursorPosition(x, y - 1);
	std::cout << "|\n";
}

bool Asteroid::Fall(int fallSpeed)
{
	if (y <= ScreenHeight() - 4)
	{
		y += fallSpeed;
		return false;
	}
	else
	{
		return true;
	}
}
