#pragma once
#include <iostream>
#include "GameObject.h"

class Player
{
public:
	Player()
	{

	}

	void HandleInputs();
	void MoveLeft();
	void MoveRight();
	void MoveUp();
	void MoveDown();
	void Draw();
};