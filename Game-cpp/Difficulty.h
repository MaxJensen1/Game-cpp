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
	//Player* player;
	//Difficulty(Player& input) : player(&input) {}

	int asteroidSpawnAmount = 10; // How many asteroids that spawn, percentage value. 100% is the most, 1% is lowest.
	int asteroidFallSpeed = 1;
	int gameUpdateTime = 100;
	int difficulty = 1;
	bool canSpawnAsteroid = true;

	void IncreaseDifficulty();
	void DifficultyText(bool displaytext);
	/*void DifficultyCountdown();
	void CountdownToText(int, bool&);*/
};