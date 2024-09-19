#include "Asteroid.h"

void Asteroid::Draw()
{
	SetColor(4);
	SetCursorPosition(x, y);
	std::cout << "O\n";
	
	SetColor(6);
	SetCursorPosition(x, y);
	std::cout << "|\n";
}

void Asteroid::Fall(int fallSpeed)
{
	y += fallSpeed;
}
