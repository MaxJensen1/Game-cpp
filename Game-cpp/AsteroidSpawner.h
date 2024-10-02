#pragma once
#include <iostream>
#include <vector>
#include "Asteroid.h"
#include "ConsoleGraphics.h"

class AsteroidSpawner: public ConsoleGraphics
{
public:
	void SpawnAsteroid(int percentage, std::vector<Asteroid*>& asteroids);
	bool spawnAsteroids = true;
};