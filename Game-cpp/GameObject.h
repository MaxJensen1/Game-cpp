#pragma once
#include <iostream>

class GameObject
{
protected:
	int x;
	int y;

public:
	GameObject(int X, int Y)
	{
		x = X;
		y = Y;
	}
};