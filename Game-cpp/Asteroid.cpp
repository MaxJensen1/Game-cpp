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

bool Asteroid::IsCollision(Player player)
{
	// Collision box for top, middle, and bottom part of the ship
	int toleranceTop = 1;
	int toleranceMiddle = 1;
	int toleranceBottom = 2;

	// Adjust the X coordinates in the collision checks to make the collision box wider
	bool topCollision = abs(x + 1 - player.x) <= toleranceTop && y == player.y; // Checks only the y-level it's on
	bool middleCollision = abs(x + 1 - player.x) <= toleranceMiddle && abs(y - player.y) <= 1; // Checks its y-level and the one above
	bool bottomCollision = abs(x + 1 - player.x) <= toleranceBottom && abs(y - player.y) <= 2; // Checks two y'levels above

	return topCollision || middleCollision || bottomCollision; // If one is true, it returns true. If all are false it returns false
}
