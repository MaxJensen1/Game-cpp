#pragma once
#include <iostream>
#include <windows.h>
#include <vector>
#include "ColorsAndCursor.h"
#include "Asteroid.h"
#include "Drawing.h"

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
	void AddToDrawQueue(Drawing& drawing);
	void SetDefaultPos();
	bool IsCollision(std::vector<Asteroid*> asteroids);

	int x;
	int y;
	int lifePoints = 3;

private:
	int prevX;
	int prevY;
};