#pragma once
#include <iostream>
#include <vector>
#include "Asteroid.h"

class AsteroidSpawner
{
public:
	AsteroidSpawner()
	{
		// Retrieve console buffer info
		CONSOLE_SCREEN_BUFFER_INFO csbi;
		GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
		consoleWidth = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	}

	void SpawnAsteroid(int percentage, std::vector<Asteroid*>& asteroids);

private:
	int consoleWidth;
};
