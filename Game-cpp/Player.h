#pragma once
#include <iostream>
#include "ColorsAndCursor.h"

class Player: public ColorsAndCursor
{
public:
	void HandleInputs();
	void MoveLeft();
	void MoveRight();
	void MoveUp();
	void MoveDown();
	void Draw();

	int x;
	int y;
};