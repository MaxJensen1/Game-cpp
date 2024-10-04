#pragma once
#include <iostream>
#include <windows.h>
#include <vector>
#include <cstdint>
#include "ConsoleGraphics.h"
#include "Asteroid.h"
#include "Drawing.h"

class Asteroid;

class Player: public ConsoleGraphics
{
public:
	Player(uint16_t X, uint16_t Y)
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
	uint16_t x;
	uint16_t y;

	// Collision box for top, middle, and bottom part of the ship
	uint8_t toleranceTop = 1;
	uint8_t toleranceMiddle = 1;
	uint8_t toleranceBottom = 2;
};