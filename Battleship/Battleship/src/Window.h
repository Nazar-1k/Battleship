#pragma once

#include <iostream>
#include "Battlefield.h"
#include "Main_menu.h"

class GameWindow
{
	friend class Battlefield;
	friend class Main_menu;
public:
	
	
	GameWindow();

	~GameWindow();

	void clearWindow();

	void pollEventWindow();

	bool isOpenWindow();
	
	void displayWindow();

	void drawWindowObjects();

private:
	sf::RenderWindow* window;
	
	sf::Event event;

	Battlefield* batlefield ;
	Battlefield* batlefieldEnemy;
	Main_menu* menu;

	
};

