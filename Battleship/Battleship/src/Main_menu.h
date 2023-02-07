#pragma once
#include "Window.h"

class Main_menu
{
public:
	friend class GameWindow;

	Main_menu();

	void draw(GameWindow& w);
	void set_font(sf::Font& arial);

private:
	sf::Text Set;
	sf::Text Auto;
	sf::Text ManUAl_SpacatioN;


};

