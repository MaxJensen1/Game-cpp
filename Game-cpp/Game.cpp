#include "Game.h"

void Game::Run()
{
	while (true)
	{
		hiScore++;

		player.HandleInputs();

		system("CLS");

		

		//Draw asteroids
		for(auto asteroid : asteroids)
		{
			asteroid.Draw();
		}
	}
}
