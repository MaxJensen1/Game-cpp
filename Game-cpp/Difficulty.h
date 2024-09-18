#pragma once
#include <iostream>
#include <thread>
#include <chrono>
#include <Windows.h>
#include "ColorsAndCursor.h"
#include "Player.h"

class Difficulty: public ColorsAndCursor
{
public:
	Player* player;
	Difficulty(Player* input) : player(input) {}

	int asteroidSpawnAmount = 10; // How many asteroids that spawn, percentage value. 100% is the most, 1% is lowest.
	int asteroidFallSpeed = 1;
	int gameUpdateTime = 100;
	int difficulty = 0;
	bool canSpawnAsteroid = true;

	void IncreaseDifficulty();
	void DifficultyText();
	void DifficultyCountdown();
	void CountdownToText(int);
};