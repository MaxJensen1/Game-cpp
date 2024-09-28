#pragma once
#include <iostream>
#include "ColorsAndCursor.h"
#include <map>
#include <conio.h> // For _kbhit() and _getch()
#include "Asteroid.h"
#include <windows.h>
#include <vector>

class Asteroid;

class Player: public ColorsAndCursor
{
public:
	Player(int X, int Y)
	{
		x = X;
		y = Y;

		SetDefaultPos();
	}
	void HandleInputs();
	void MoveLeft();
	void MoveRight();
	void MoveUp();
	void MoveDown();
	void Draw();
	void SetDefaultPos();
	bool IsCollision(std::vector<Asteroid*> asteroids);

	int x;
	int y;
	int lifePoints = 3;
};