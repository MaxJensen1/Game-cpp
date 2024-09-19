#pragma once
#include <iostream>
#include <random>
#include <vector>
#include "ColorsAndCursor.h"
#include "Player.h"

class Asteroid : public ColorsAndCursor
{
public:
	Asteroid(int X, int Y) : x(X), y(Y) {}

	void Draw();
	bool Fall(int fallSpeed);

	int x;
	int y;

private:
	ColorsAndCursor colorsAndCursor;
};