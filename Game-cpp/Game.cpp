#include "Game.h"

void Game::Run()
{
	while (true)
	{
		hiScore++;
		system("CLS");
		player.Draw();
		player.HandleInputs();

		asteroidSpawner.SpawnAsteroid(difficulty.asteroidSpawnAmount, asteroids);

		std::this_thread::sleep_for(std::chrono::milliseconds(15));
	}

	/*CountdownTimer timer(15);
	timer.Start();*/

	//while (true)
	//{
	//	hiScore++;

	//	player.HandleInputs();

	//	system("CLS");

	//	player.Draw();

	//	// timer stuff

	//	//asteroidSpawner.SpawnAsteroid(difficulty.asteroidSpawnAmount, asteroids);

	//	//Draw asteroids and check collision
	//	for (auto asteroid : asteroids)
	//	{
	//		asteroid->Draw();

	//		/*if (player.IsCollision(asteroid))
	//		{
	//			player.lifePoints--;
	//		}*/
	//	}

	//	if (player.lifePoints <= 0)
	//	{
	//		ContinueOrExit();
	//	}

	//	/*if (timer.timeInSeconds <= 0)
	//	{
	//		difficulty.IncreaseDifficulty();
	//	}*/
	//}
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
