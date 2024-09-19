#pragma once
#include <iostream>
#include <chrono>
#include <vector>
#include <thread>
#include "Player.h"
#include "Asteroid.h"
#include "Difficulty.h"
#include "AsteroidSpawner.h"
#include "CountdownTimer.h"

class Game
{
public:
	Game(): player(5, 4)
	{

	}

	void Run();

private:
	int hiScore = 0;
	int asteroidSpawnAmount = 10; // How many asteroids that spawn, percentage value. 100% is the most, 1% is lowest.
	int asteroidFallSpeed = 1;
	int gameUpdateTime = 100;

	Player player;

	std::vector<Asteroid*> asteroids;
	Difficulty difficulty;
	AsteroidSpawner asteroidSpawner;

	void AsteroidsAndCollision();
	void ContinueOrExit();
	void Reset();
};