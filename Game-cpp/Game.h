#pragma once
#include <iostream>
#include <chrono>
#include <vector>
#include "Player.h"
#include "Asteroid.h"

class Game
{
public:
	Game()
	{

	}
	void Run();

private:
	int hiScore = 0;
	Player player;
	std::vector<Asteroid*> asteroids;
};