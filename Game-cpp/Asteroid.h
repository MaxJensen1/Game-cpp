#pragma once
#include <iostream>
#include "ColorsAndCursor.h"
#include "Player.h"

class Asteroid : public ColorsAndCursor
{
public:
	void Draw();
	void Fall(int fallSpeed);
	bool IsCollision(Player player);

	int x;
	int y;

private:
	ColorsAndCursor colorsAndCursor;
};