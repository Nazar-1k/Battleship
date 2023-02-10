#include "Ship.h"
#include <iostream>

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

void Ship::moveShip(Ship& ship)
{
	this->x = ship.x;
	this->y = ship.y;

	this->count_deck = ship.count_deck;

	this-> verticalShip = ship.verticalShip;
	this-> show = ship.show;
}

void Ship::Ship_info()
{
	std::cout << "x ->\t" << x << std::endl;
	std::cout << "y ->\t" << y << std::endl;
	std::cout << "count_deck ->\t" << count_deck << std::endl;
	std::cout << "verticalShip ->\t" << verticalShip << std::endl;
	std::cout << "show ->\t" << show << std::endl;
}

bool Ship::ship_exist()
{
	if(x == -1 or y == -1)
		return false;

	return true;
}


int Ship::count_ship;
int Ship::count_ship_1;
int Ship::count_ship_2;
int Ship::count_ship_3;
int Ship::count_ship_4;

