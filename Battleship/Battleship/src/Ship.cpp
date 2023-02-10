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

	if (count_deck == 1)
		this->count_ship_1++;

	if (count_deck == 2)
		this->count_ship_2++;

	if (count_deck == 3)
		this->count_ship_3++;

	if (count_deck == 4)
		this->count_ship_4++;
	this->count_ship++;
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
		return x == -1 or y == -1;
}


void Ship::deleteShip()
{
	x = -1;
	y = -1;
}

bool  Ship::ship_x_y(int x, int y)
{
	return this->x == x and this->y == y;
}

void Ship::delete_used_ship(int x, int y, Ship& ship1, Ship& ship2, Ship& ship3, Ship& ship4, Ship& ship5, Ship& ship6, Ship& ship7, Ship& ship8, Ship& ship9, Ship& ship10, Ship& ship11, Ship& ship12, Ship& ship13)
{
	if (!ship1.ship_exist())
	{
		if (ship1.ship_x_y(x, y))
		{
			ship1.deleteShip();
			return;
		}
	}
	else if (!ship2.ship_exist())
	{
		if (ship2.ship_x_y(x, y))
		{
			ship2.deleteShip();
			return;
		}
	}
	else if (!ship3.ship_exist())
	{
		if (ship3.ship_x_y(x, y))
		{
			ship3.deleteShip();
			return;
		}
	}
	else if (!ship4.ship_exist())
	{
		if (ship4.ship_x_y(x, y))
		{
			ship4.deleteShip();
			return;
		}
	}
	else if (!ship5.ship_exist())
	{
		if (ship5.ship_x_y(x, y))
		{
			ship5.deleteShip();
			return;
		}
	}
	else if (!ship6.ship_exist())
	{
		if (ship6.ship_x_y(x, y))
		{
			ship6.deleteShip();
			return;
		}
	}
	else if (!ship7.ship_exist())
	{
		if (ship7.ship_x_y(x, y))
		{
			ship7.deleteShip();
			return;
		}
	}
	else if (!ship8.ship_exist())
	{
		if (ship8.ship_x_y(x, y))
		{
			ship8.deleteShip();
			return;
		}
	}
	else if (!ship9.ship_exist())
	{
		if (ship9.ship_x_y(x, y))
		{
			ship9.deleteShip();
			return;
		}
	}
	else if (!ship10.ship_exist())
	{
		if (ship10.ship_x_y(x, y))
		{
			ship10.deleteShip();
			return;
		}
	}
	else if (!ship11.ship_exist())
	{
		if (ship11.ship_x_y(x, y))
		{
			ship11.deleteShip();
			return;
		}
	}
	else if (!ship12.ship_exist())
	{
		if (ship12.ship_x_y(x, y))
		{
			ship12.deleteShip();
			return;
		}
	}
	else if (!ship13.ship_exist())
	{
		if (ship13.ship_x_y(x, y))
		{
			ship13.deleteShip();
			return;
		}
	}
}

void Ship::delete_used_ship(int x, int y, Ship& ship1, Ship& ship2, Ship& ship3, Ship& ship4, Ship& ship5, Ship& ship6)
{
	if (!ship1.ship_exist())
	{
		if (ship1.ship_x_y(x, y))
		{
			ship1.deleteShip();
			return;
		}
	}
	else if (!ship2.ship_exist())
	{
		if (ship2.ship_x_y(x, y))
		{
			ship2.deleteShip();
			return;
		}
	}
	else if (!ship3.ship_exist())
	{
		if (ship3.ship_x_y(x, y))
		{
			ship3.deleteShip();
			return;
		}
	}
	else if (!ship4.ship_exist())
	{
		if (ship4.ship_x_y(x, y))
		{
			ship4.deleteShip();
			return;
		}
	}
	else if (!ship5.ship_exist())
	{
		if (ship5.ship_x_y(x, y))
		{
			ship5.deleteShip();
			return;
		}
	}
	else if (!ship6.ship_exist())
	{
		if (ship6.ship_x_y(x, y))
		{
			ship6.deleteShip();
			return;
		}
	}
}

void Ship::delete_used_ship(int x, int y, Ship& ship1, Ship& ship2, Ship& ship3)
{
	if (!ship1.ship_exist())
	{
		if (ship1.ship_x_y(x, y))
		{
			ship1.deleteShip();
			return;
		}
	}
	else if (!ship2.ship_exist())
	{
		if (ship2.ship_x_y(x, y))
		{
			ship2.deleteShip();
			return;
		}
	}
	else if (!ship3.ship_exist())
	{
		if (ship3.ship_x_y(x, y))
		{
			ship3.deleteShip();
			return;
		}
	}
}


int Ship::count_ship;
int Ship::count_ship_1;
int Ship::count_ship_2;
int Ship::count_ship_3;
int Ship::count_ship_4;

