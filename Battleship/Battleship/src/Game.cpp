#include "Game.h"

Game::Game()
{

}

Game::~Game()
{
	delete window;
}

void Game::run()
{
	while (window->isOpenWindow())
	{
		window->pollEventWindow();

		window->clearWindow();

		window->drawWindowObjects();

		window->displayWindow();
	}
}