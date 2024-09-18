#pragma once
#include <iostream>
#include "Colors.h"

class Asteroid: public Colors
{
public:
	Asteroid()
	{

	}

	void Draw();

private:
	Colors colors;
};