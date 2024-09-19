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
		levelTimer.UpdateTimer(hiScore);

		/*if (levelTimer.timeInSeconds <= 0)
		{
			std::cout << "restart" << std::endl;
			levelTimer = CountdownTimer(15);
			levelTimer.Start();
		}*/

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

void Game::AsteroidsAndCollision()
{

}

void Game::ContinueOrExit()
{

}

void Game::Reset()
{

}
