#pragma once
#include <iostream>
#include "ColorsAndCursor.h"
#include <map>
#include <conio.h> // For _kbhit() and _getch()
#include "Asteroid.h"
#include <windows.h>

class Player: public ColorsAndCursor
{
public:
	Player(int X, int Y)
	{
		x = X;
		y = Y;
	}
	void HandleInputs();
	void MoveLeft();
	void MoveRight();
	void MoveUp();
	void MoveDown();
	void Draw();
	void SetDefaultPos();
	//bool IsCollision(Asteroid* asteroid);

	int x;
	int y;
	int lifePoints = 3;
};