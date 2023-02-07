#pragma once

#include "Field.h"

class Ship : Field
{
public:

	Ship();
	Ship(int i, int j, bool verticalShip);

	void unsetShip(int &count);
	void unsetShip(int& count, int n);
	void unsetShip();

	void ubdatecoord(int i, int j, bool verticalShip);

	void createShip(int i, int j, bool verticalShip, int count_deck);
private:
	int i;
	int j;
	int count_deck;

	bool verticalShip;
	
	bool  show;
	bool life;
};
