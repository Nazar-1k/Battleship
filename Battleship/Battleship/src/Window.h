#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Battlefield.h"

using namespace sf;


class GameWindow
{
	friend class Battlefield;
public:
	
	GameWindow();

	~GameWindow();

	void clearWindow();

	void pollEventWindow();

	bool isOpenWindow();
	
	void displayWindow();

	void drawWindowObjects();

private:
	RenderWindow* window;
	
	Event event;

	Battlefield* batlefield ;
	Battlefield* batlefieldEnemy;
	
};
