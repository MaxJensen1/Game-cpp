#include "AsteroidSpawner.h"

void AsteroidSpawner::SpawnAsteroid(int spawnPercentage, std::vector<Asteroid*>& asteroids)
{
	if (!spawnAsteroids) // Return if it shouldn't do anything
	{
		return;
	}

	// Initialize random number generators
	std::random_device rd;  // Random device to seed the generator
	std::mt19937 generator(rd()); // mt stands for Mersenne Twister random number generator
	std::uniform_int_distribution<> randomSpawnChance(0, 100);
	std::uniform_int_distribution<> randomSpawnLocationX(2, ScreenWidth() - 1);

	if (randomSpawnChance(generator) <= spawnPercentage)
	{
		asteroids.push_back(new Asteroid(randomSpawnLocationX(generator), 0));
	}
}