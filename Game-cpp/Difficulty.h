#pragma once
#include <iostream>
#include <thread>
#include <chrono>
#include <Windows.h>
#include "ConsoleGraphics.h"
#include "Player.h"

class Difficulty: public ConsoleGraphics
{
public:
	uint8_t asteroidSpawnAmount = 1; // How many asteroids that spawn, percentage value. 100% is the most, 1% is lowest.
	uint8_t asteroidFallSpeed = 1;
	uint8_t difficulty = 1;
	bool canSpawnAsteroid = true;

	void IncreaseDifficulty();
	void DifficultyText(bool displaytext);
};