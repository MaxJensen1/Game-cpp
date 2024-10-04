#pragma once
#include <iostream>
#include <random>
#include <vector>
#include <cstdint>
#include "ConsoleGraphics.h"
#include "Player.h"
#include "Drawing.h"

class Asteroid : public ConsoleGraphics
{
public:
	Asteroid(uint16_t X, uint16_t Y) : x(X), y(Y) {}
	void AddToDrawQueue(Drawing& drawing);
	bool Fall(uint8_t fallSpeed);

public:
	uint16_t x;
	uint16_t y;

private:
	ConsoleGraphics colorsAndCursor;
};