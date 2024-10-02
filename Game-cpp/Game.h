#pragma once
#include <iostream>
#include <chrono>
#include <vector>
#include <thread>
#include <atomic>
#include "Player.h"
#include "Asteroid.h"
#include "Difficulty.h"
#include "AsteroidSpawner.h"
#include "CountdownTimer.h"
#include "ConsoleGraphics.h"
#include "Drawing.h"

class Game: public ConsoleGraphics
{
public:
	Game(): player(5, 4), levelTimer(secondsPerLevel), timerBetweenLevels(secondsBetweenLevels), asteroidFallTimer(2)
	{

	}

	void Run();

private:
	int hiScore = 0;
	int asteroidFallSpeed = 1; // 1 by default
	int gameUpdateTime = 100;
	int secondsPerLevel = 15;
	int secondsBetweenLevels = 6;
	float asteroidFallDelay = 0.025f;
	bool levelActive = true;
	bool printDifficulty = false;

private:
	// Using atomic variables because multiple threads can access them without interfering each other
	std::atomic<int> updates{ 0 };
	std::atomic<int> ups{ 0 };

private:
	std::vector<Asteroid*> asteroids;
	Player player;
	Difficulty difficulty;
	AsteroidSpawner asteroidSpawner;
	CountdownTimer levelTimer;
	CountdownTimer timerBetweenLevels;
	CountdownTimer asteroidFallTimer;
	Drawing drawing;

private:
	void LevelsCheck();
	void HandleAsteroids();
	void ContinueOrExit();
	void Reset();
	void StartUPSThread();
};