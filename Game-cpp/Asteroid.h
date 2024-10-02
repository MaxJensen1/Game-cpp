#pragma once
#include <iostream>
#include <random>
#include <vector>
#include "ConsoleGraphics.h"
#include "Player.h"
#include "Drawing.h"

class Asteroid : public ConsoleGraphics
{
public:
	Asteroid(int X, int Y) : x(X), y(Y) {}

	void AddToDrawQueue(Drawing& drawing);
	bool Fall(int fallSpeed);

	int x;
	int y;

private:
	ConsoleGraphics colorsAndCursor;
};