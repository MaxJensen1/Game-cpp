#pragma once
#include <iostream>
#include <windows.h>
#include <vector>
#include "ConsoleGraphics.h"
#include "Asteroid.h"
#include "Drawing.h"

class Asteroid;

class Player: public ConsoleGraphics
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

public:
	int x;
	int y;

private:
	int prevX;
	int prevY;
};