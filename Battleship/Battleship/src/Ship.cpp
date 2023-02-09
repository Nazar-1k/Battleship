#include "Ship.h"

Ship::Ship()
	:x(-1), y(-1), verticalShip(false), count_deck(1), show(true)
{ }

void Ship::setx(int x)
{
	this->x = x;
}

void Ship::sety(int y)
{
	this->y = y;
}

void Ship::setCount_deck(int count_deck)
{
	this->count_deck = count_deck;
}

void Ship::setVerticalShip(bool verticalShip)
{
	this->verticalShip = verticalShip;
}

void Ship::setShow(bool show)
{
	this->show = show;
}

void Ship::creatShip(int x, int y, bool verticalShip, int count_deck)
{
	this->x = x;
	this->y = y;
	this->verticalShip = verticalShip;
	this->count_deck = count_deck;
}


void Ship::set_CountShip(int count)
{
	Ship::count_ship = count;
}

void Ship::set_CountShip_1(int count)
{
	Ship::count_ship_1 = count;
}

void Ship::set_CountShip_2(int count)
{
	Ship::count_ship_2 = count;
}

void Ship::set_CountShip_3(int count)
{
	Ship::count_ship_3 = count;
}

void Ship::set_CountShip_4(int count)
{
	Ship::count_ship_4 = count;
}


int Ship::count_ship;
int Ship::count_ship_1;
int Ship::count_ship_2;
int Ship::count_ship_3;
int Ship::count_ship_4;

