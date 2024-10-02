#include "Game.h"

void Game::Run()
{
	HideConsoleCursor();

	asteroidFallTimer.Start();
	levelTimer.Start();

	StartUPSThread(); // Run updates per second counter on a separate thread

	while (true)
	{
		updates++;
		drawing.ClearQueue(); // Clears the previous loop's drawing array

		player.HandleInputs();
		player.AddToDrawQueue(drawing);
		LevelsCheck(); // Keeps track of the levels with timers, draws timer and Hi-Score and increases difficulty
		HandleAsteroids(); // Spawn asteroids, draw them and check collisions with the player

		drawing.DrawGame(); // Prints the drawing array

		if (levelActive) { hiScore++; } // Only add to the Hi-Score while a level is active

	    std::this_thread::sleep_for(std::chrono::milliseconds(25));

		// Display UPS value (updated by the separate thread)
		SetCursorPosition(0, 1); // Adjust cursor position to where you want to display UPS
		SetColor(WHITE);
		std::cout << "UPS: " << ups << "        " << std::flush; // Print UPS with enough spacing
	}
}

void Game::LevelsCheck()
{
	// Update and check the timer
	if (levelActive && levelTimer.UpdateTimer(hiScore, secondsPerLevel, true) >= secondsPerLevel)
	{
		difficulty.IncreaseDifficulty();
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
		difficulty.DifficultyText(false);
		// Stop the between-level timer and reset everything to start a new level
		timerBetweenLevels.Stop();
		asteroidSpawner.spawnAsteroids = true;
		levelActive = true;
		printDifficulty = false;

		levelTimer = CountdownTimer(secondsPerLevel);
		levelTimer.Restart();
	}

	if (printDifficulty) { difficulty.DifficultyText(true); } // Prints the difficulty text once a level has been completed
}

void Game::HandleAsteroids()
{
	asteroidSpawner.SpawnAsteroid(difficulty.asteroidSpawnAmount, asteroids);

	for (auto asteroid = asteroids.begin(); asteroid != asteroids.end();) // Loop through the enitre array
	{
		if ((*asteroid)->Fall(asteroidFallSpeed)) // Returns true when asteroids have reached the bottom
		{
			delete* asteroid; // Delete the asteroid
			asteroid = asteroids.erase(asteroid); // Erase from the vector
		}
		else
		{
			(*asteroid)->AddToDrawQueue(drawing); // Draw the asteroid if it's not deleted
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
	SetColor(LIGHT_RED);
	system("CLS");
	std::cout << "Game over!" << "\n";

	SetColor(WHITE);
	std::cout << "Completed levels: " << (difficulty.difficulty - 1) << "\n";
	std::cout << "HI-Score: " << hiScore << "\n";
	std::cout << "\nPress [ESC] to exit or [ENTER] to play again." << "\n";

	while (true) // Loop until the right key press.
	{
		if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) // Check if ESC key is pressed
		{
			system("CLS");
			SetColor(RED);
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
	system("CLS");
	hiScore = 0;
	asteroids.clear();
	player.SetDefaultPos();
	asteroidFallSpeed = 1;
	difficulty.asteroidSpawnAmount = 10;
	difficulty.difficulty = 0;
	levelTimer.Restart();
}

void Game::StartUPSThread()
{
	// Start a thread that continuously updates the UPS value every 0,5 seconds
	std::thread upsThread([this]()
	{
		while (true)
		{
			// Store the current number of updates and reset the counter
			int currentUpdates = updates.exchange(0);

			ups = currentUpdates;

			std::this_thread::sleep_for(std::chrono::milliseconds(500)); // Sleep for 0,5 seconds
		}
	});

	upsThread.detach(); // Detach thread to let it run independently
}