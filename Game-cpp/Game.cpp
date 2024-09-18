#include "Game.h"

void Game::Run()
{
	asteroids.push_back(new Asteroid);

	while (true)
	{
		hiScore++;

		player.HandleInputs();

		system("CLS");

		//Draw asteroids
		for(auto asteroid : asteroids)
		{
			asteroid->Draw();
		}

		player.Draw();


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
