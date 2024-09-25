#include "Game.h"

void Game::Run()
{
	//levelTimer.Start();
	while (true)
	{
		hiScore++;
		system("CLS");
		player.Draw();
		player.HandleInputs();

		// Update and check the timer
		if (levelTimer.UpdateTimer(hiScore, secondsPerLevel) >= secondsPerLevel)
		{
			levelTimer = CountdownTimer(secondsPerLevel);
			levelTimer.StartAndRestart();
			ContinueOrExit();
		}

		asteroidSpawner.SpawnAsteroid(difficulty.asteroidSpawnAmount, asteroids);

		for (auto asteroid = asteroids.begin(); asteroid != asteroids.end();)
		{
			if ((*asteroid)->Fall(asteroidFallSpeed)) // Returns true when asteroids have reached the bottom
			{
				delete* asteroid; // Delete the asteroid
				asteroid = asteroids.erase(asteroid); // Erase from the vector
			}
			else
			{
				(*asteroid)->Draw(); // Draw the asteroid if it's not deleted
				++asteroid; // Move to the next asteroid
			}

			/*if (player.IsCollision(asteroid))
			{
				std::cout << "take damage" << std::endl;
			}*/
		}

	    std::this_thread::sleep_for(std::chrono::milliseconds(25));
	}
}

void Game::ContinueOrExit()
{
	system("CLS");
	std::cout << "Game over!" << "\n";
	if (difficulty.difficulty > 1)
	{
		std::cout << "Completed levels: " << (difficulty.difficulty - 1) << "\n";
	}
	else
	{
		std::cout << "Completed levels: " << (difficulty.difficulty) << "\n";
	}
	std::cout << "HI-Score: " << hiScore << "\n";
	std::cout << "Press [ESC] to exit or [ENTER] to play again." << "\n";

	std::cin;

	if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) // Check if ESC key is pressed
	{
		std::cout << "Escape key pressed, exiting...\n";
		exit(0);
	}
	else if (GetAsyncKeyState(VK_RETURN) & 0x8000) 
	{
		Reset();
		Run();
	}
	else // Causing flickering because the funciton is called over and over again
	{
		ContinueOrExit();
	}
}

void Game::Reset()
{
	asteroids.clear();
	player.SetDefaultPos();
	asteroidFallSpeed = 1;
	asteroidSpawnAmount = 10;
}
