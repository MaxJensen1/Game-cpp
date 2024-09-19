#pragma once
#include <iostream>
#include <vector>
#include "Asteroid.h"
#include "ColorsAndCursor.h"

class AsteroidSpawner: public ColorsAndCursor
{
public:
	void SpawnAsteroid(int percentage, std::vector<Asteroid*>& asteroids);
};
