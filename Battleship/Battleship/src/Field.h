#pragma once

#include <SFML/Graphics.hpp>

class Field
{
	friend class Battlefield;
public:
	
	Field();

private:
	sf::RectangleShape faield;
	sf::Color color;

	int x;
	int y;

	bool cursorIsGiven;

	bool ship;
	bool noShip;
};
