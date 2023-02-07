#pragma once

#include <SFML/Graphics.hpp>
using namespace sf;

class Field
{
	friend class Battlefield;
public:
	
	Field();

private:
	RectangleShape faield;
	Color color;

	int x;
	int y;

	bool cursorIsGiven;

	bool ship;
	bool noShip;
};
