#pragma once
#include "Window.h"



class Game
{
public:
	Game();


	~Game();


	void run();
	

private:
	GameWindow* window = new GameWindow();
	
	
};