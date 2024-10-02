#include "Asteroid.h"

void Asteroid::AddToDrawQueue(Drawing& drawing)
{
	///////////
	//       //
	//   |   //
	//   O   //
	//       //
	///////////

	drawing.AddToDrawQueue(x, y + 1, '|', YELLOW);
	drawing.AddToDrawQueue(x, y + 2, 'O', RED);
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