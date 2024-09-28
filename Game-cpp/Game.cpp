#include "Game.h"

void Game::Run()
{
	asteroidFallTimer.Start();
	levelTimer.Start();

	while (true)
	{
		system("CLS"); // Clear the console

		player.Draw();
		player.HandleInputs();
		LevelsCheck(); // Keeps track of the levels with timers, draws timer and Hi-Score and increases difficulty
		HandleAsteroids(); // Spawn asteroids, draw them and check collisions with the player

		if (levelActive) { hiScore++; } // Only add to the Hi-Score while a level is active

	    std::this_thread::sleep_for(std::chrono::milliseconds(20));
	}
}

void Game::LevelsCheck()
{
	// Update and check the timer
	if (levelActive && levelTimer.UpdateTimer(hiScore, secondsPerLevel, true) >= secondsPerLevel)
	{
		asteroidSpawner.spawnAsteroids = false;
		levelTimer.Stop();
		levelActive = false;
		printDifficulty = true;

		// Start the timer between levels and show difficulty increase text
		timerBetweenLevels = CountdownTimer(secondsBetweenLevels);
		timerBetweenLevels.Start();
	}

	if (!levelActive && timerBetweenLevels.UpdateTimer(secondsBetweenLevels) >= secondsBetweenLevels)
	{
		// Stop the between-level timer and reset everything to start a new level
		timerBetweenLevels.Stop();
		asteroidSpawner.spawnAsteroids = true;
		levelActive = true;
		printDifficulty = false;

		levelTimer = CountdownTimer(secondsPerLevel);
		levelTimer.Restart();
	}

	if (printDifficulty) { difficulty.DifficultyText(); } // Prints the difficulty text once a level has been completed
}

void Game::HandleAsteroids()
{
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
		
		if (player.IsCollision(asteroids))
		{
			ContinueOrExit();
		}
	}
}

void Game::ContinueOrExit()
{
	SetColor(12);
	system("CLS");
	std::cout << "Game over!" << "\n";

	SetColor(7);
	if (difficulty.difficulty > 1)
	{
		std::cout << "Completed levels: " << (difficulty.difficulty - 1) << "\n";
	}
	else
	{
		std::cout << "Completed levels: " << (difficulty.difficulty) << "\n";
	}
	std::cout << "HI-Score: " << hiScore << "\n";
	std::cout << "\nPress [ESC] to exit or [ENTER] to play again." << "\n";

	while (true) // Loop until the right key press.
	{
		if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) // Check if ESC key is pressed
		{
			system("CLS");
			SetColor(4);
			std::cout << "Escape key pressed, exiting...\n";
			exit(0);
		}
		else if (GetAsyncKeyState(VK_RETURN) & 0x8000) // Check if ENTER key is pressed
		{
			Reset();
			Run();
			break; // Exit the loop once Run() is called
		}
	}
}

void Game::Reset()
{
	hiScore = 0;
	asteroids.clear();
	player.SetDefaultPos();
	asteroidFallSpeed = 1;
	difficulty.asteroidSpawnAmount = 10;
}