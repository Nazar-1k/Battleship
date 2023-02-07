#include "Ship.h"



Ship::Ship()
{
	this->i = -1;
	this->j = -1;
	this->verticalShip = false;
}

Ship::Ship(int i, int j, bool verticalShip)
{
	this->i = i;
	this->j = j;
	this->verticalShip = verticalShip;
}

void Ship::unsetShip(int& count)
{
	this->i = -1;
	this->j = -1;
	count--;
}

void Ship::unsetShip(int& count,int n)
{
	this->i = -1;
	this->j = -1;
	count-=n;
}

void Ship::unsetShip()
{
	this->i = -1;
	this->j = -1;
}

void Ship::ubdatecoord(int i, int j, bool verticalShip)
{
	this->i = i;
	this->j = j;
	this->verticalShip = verticalShip;
}

void Ship::createShip(int i, int j, bool verticalShip, int count_deck)
{
	this->i = i;
	this->j = j;
	this->verticalShip = verticalShip;
	this->count_deck = count_deck;
}


