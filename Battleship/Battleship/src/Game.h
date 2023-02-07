#pragma once
#include "Battlefield.h"

using namespace sf;


class Game
{
public:
	Game();


	~Game();


	void run();
	

private:
	GameWindow* window = new GameWindow();
	
	
};