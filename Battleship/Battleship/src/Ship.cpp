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

	ship.deleteShip();
}
void  Ship::move_ship_3(Ship& ship1, Ship& ship2, Ship& ship3)
{
	if (ship1.ship_exist() and !ship3.ship_exist())
			ship1.moveShip(ship3);
	else if(ship2.ship_exist() and !ship3.ship_exist())
		ship2.moveShip(ship3);
}

void  Ship::move_ship_2(Ship& ship1, Ship& ship2, Ship& ship3, Ship& ship4, Ship& ship5, Ship& ship6)
{
	if (ship1.ship_exist())
	{
		if (!ship4.ship_exist())
			ship1.moveShip(ship4);
		
		else if (!ship5.ship_exist())
			ship1.moveShip(ship5);

		else if (!ship6.ship_exist())
			ship1.moveShip(ship6);
	}
	
	if (ship2.ship_exist())
	{
		if (!ship4.ship_exist())
			ship2.moveShip(ship4);

		else if (!ship5.ship_exist())
			ship2.moveShip(ship5);

		else if (!ship6.ship_exist())
			ship2.moveShip(ship6);
	}

	if(ship3.ship_exist())
	{
		if (!ship4.ship_exist())
			ship3.moveShip(ship4);

		else if (!ship5.ship_exist())
			ship3.moveShip(ship5);

		else if (!ship6.ship_exist())
			ship3.moveShip(ship6);
	}
}

void  Ship::move_ship_1(Ship& ship1, Ship& ship2, Ship& ship3, Ship& ship4, Ship& ship5, Ship& ship6, Ship& ship7, Ship& ship8, Ship& ship9, Ship& ship10, Ship& ship11, Ship& ship12, Ship& ship13)
{
	if (ship1.ship_exist())
	{
		if (!ship5.ship_exist())
			ship1.moveShip(ship5);

		else if (!ship6.ship_exist())
			ship1.moveShip(ship6);
		
		else if (!ship7.ship_exist())
			ship1.moveShip(ship7);

		else if (!ship8.ship_exist())
			ship1.moveShip(ship8);

		else if (!ship9.ship_exist())
			ship1.moveShip(ship9);

		else if (!ship10.ship_exist())
			ship1.moveShip(ship10);

		else if (!ship11.ship_exist())
			ship1.moveShip(ship11);

		else if (!ship12.ship_exist())
			ship1.moveShip(ship12);

		else if (!ship13.ship_exist())
			ship1.moveShip(ship13);
	}
	if (ship2.ship_exist())
	{
		if (!ship5.ship_exist())
			ship2.moveShip(ship5);

		else if (!ship6.ship_exist())
			ship2.moveShip(ship6);

		else if (!ship7.ship_exist())
			ship2.moveShip(ship7);

		else if (!ship8.ship_exist())
			ship2.moveShip(ship8);

		else if (!ship9.ship_exist())
			ship2.moveShip(ship9);

		else if (!ship10.ship_exist())
			ship2.moveShip(ship10);

		else if (!ship11.ship_exist())
			ship2.moveShip(ship11);

		else if (!ship12.ship_exist())
			ship2.moveShip(ship12);

		else if (!ship13.ship_exist())
			ship2.moveShip(ship13);
	}
	if (ship3.ship_exist())
	{
		if (!ship5.ship_exist())
			ship3.moveShip(ship5);

		else if (!ship6.ship_exist())
			ship3.moveShip(ship6);

		else if (!ship7.ship_exist())
			ship3.moveShip(ship7);

		else if (!ship8.ship_exist())
			ship3.moveShip(ship8);

		else if (!ship9.ship_exist())
			ship3.moveShip(ship9);

		else if (!ship10.ship_exist())
			ship3.moveShip(ship10);

		else if (!ship11.ship_exist())
			ship3.moveShip(ship11);

		else if (!ship12.ship_exist())
			ship3.moveShip(ship12);

		else if (!ship13.ship_exist())
			ship3.moveShip(ship13);
	}
	if (ship4.ship_exist())
	{
		if (!ship5.ship_exist())
			ship4.moveShip(ship5);

		else if (!ship6.ship_exist())
			ship4.moveShip(ship6);

		else if (!ship7.ship_exist())
			ship4.moveShip(ship7);

		else if (!ship8.ship_exist())
			ship4.moveShip(ship8);

		else if (!ship9.ship_exist())
			ship4.moveShip(ship9);

		else if (!ship10.ship_exist())
			ship4.moveShip(ship10);

		else if (!ship11.ship_exist())
			ship4.moveShip(ship11);

		else if (!ship12.ship_exist())
			ship4.moveShip(ship12);

		else if (!ship13.ship_exist())
			ship4.moveShip(ship13);
	}
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
			move_ship_1(ship1, ship2, ship3, ship4, ship5, ship6, ship7, ship8, ship9, ship10, ship11, ship12, ship13);
			return;
		}
	}
	else if (!ship2.ship_exist())
	{
		if (ship2.ship_x_y(x, y))
		{
			ship2.deleteShip();
			move_ship_1(ship1, ship2, ship3, ship4, ship5, ship6, ship7, ship8, ship9, ship10, ship11, ship12, ship13);
			return;
		}
	}
	else if (!ship3.ship_exist())
	{
		if (ship3.ship_x_y(x, y))
		{
			ship3.deleteShip();
			move_ship_1(ship1, ship2, ship3, ship4, ship5, ship6, ship7, ship8, ship9, ship10, ship11, ship12, ship13);
			return;
		}
	}
	else if (!ship4.ship_exist())
	{
		if (ship4.ship_x_y(x, y))
		{
			ship4.deleteShip();
			move_ship_1(ship1, ship2, ship3, ship4, ship5, ship6, ship7, ship8, ship9, ship10, ship11, ship12, ship13);
			return;
		}
	}
	else if (!ship5.ship_exist())
	{
		if (ship5.ship_x_y(x, y))
		{
			ship5.deleteShip();
			move_ship_1(ship1, ship2, ship3, ship4, ship5, ship6, ship7, ship8, ship9, ship10, ship11, ship12, ship13);
			return;
		}
	}
	else if (!ship6.ship_exist())
	{
		if (ship6.ship_x_y(x, y))
		{
			ship6.deleteShip();
			move_ship_1(ship1, ship2, ship3, ship4, ship5, ship6, ship7, ship8, ship9, ship10, ship11, ship12, ship13);
			return;
		}
	}
	else if (!ship7.ship_exist())
	{
		if (ship7.ship_x_y(x, y))
		{
			ship7.deleteShip();
			move_ship_1(ship1, ship2, ship3, ship4, ship5, ship6, ship7, ship8, ship9, ship10, ship11, ship12, ship13);
			return;
		}
	}
	else if (!ship8.ship_exist())
	{
		if (ship8.ship_x_y(x, y))
		{
			ship8.deleteShip();
			move_ship_1(ship1, ship2, ship3, ship4, ship5, ship6, ship7, ship8, ship9, ship10, ship11, ship12, ship13);
			return;
		}
	}
	else if (!ship9.ship_exist())
	{
		if (ship9.ship_x_y(x, y))
		{
			ship9.deleteShip();
			move_ship_1(ship1, ship2, ship3, ship4, ship5, ship6, ship7, ship8, ship9, ship10, ship11, ship12, ship13);
			return;
		}
	}
	else if (!ship10.ship_exist())
	{
		if (ship10.ship_x_y(x, y))
		{
			ship10.deleteShip();
			move_ship_1(ship1, ship2, ship3, ship4, ship5, ship6, ship7, ship8, ship9, ship10, ship11, ship12, ship13);
			return;
		}
	}
	else if (!ship11.ship_exist())
	{
		if (ship11.ship_x_y(x, y))
		{
			ship11.deleteShip();
			move_ship_1(ship1, ship2, ship3, ship4, ship5, ship6, ship7, ship8, ship9, ship10, ship11, ship12, ship13);
			return;
		}
	}
	else if (!ship12.ship_exist())
	{
		if (ship12.ship_x_y(x, y))
		{
			ship12.deleteShip();
			move_ship_1(ship1, ship2, ship3, ship4, ship5, ship6, ship7, ship8, ship9, ship10, ship11, ship12, ship13);
			return;
		}
	}
	else if (!ship13.ship_exist())
	{
		if (ship13.ship_x_y(x, y))
		{
			ship13.deleteShip();
			move_ship_1(ship1, ship2, ship3, ship4, ship5, ship6, ship7, ship8, ship9, ship10, ship11, ship12, ship13);
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
			move_ship_2(ship1, ship2, ship3, ship4, ship5, ship6);
			return;
		}
	}
	else if (!ship2.ship_exist())
	{
		if (ship2.ship_x_y(x, y))
		{
			ship2.deleteShip();
			move_ship_2(ship1, ship2, ship3, ship4, ship5, ship6);
			return;
		}
	}
	else if (!ship3.ship_exist())
	{
		if (ship3.ship_x_y(x, y))
		{
			ship3.deleteShip();
			move_ship_2(ship1, ship2, ship3, ship4, ship5, ship6);
			return;
		}
	}
	else if (!ship4.ship_exist())
	{
		if (ship4.ship_x_y(x, y))
		{
			ship4.deleteShip();
			move_ship_2(ship1, ship2, ship3, ship4, ship5, ship6);
			return;
		}
	}
	else if (!ship5.ship_exist())
	{
		if (ship5.ship_x_y(x, y))
		{
			ship5.deleteShip();
			move_ship_2(ship1, ship2, ship3, ship4, ship5, ship6);
			return;
		}
	}
	else if (!ship6.ship_exist())
	{
		if (ship6.ship_x_y(x, y))
		{
			ship6.deleteShip();
			move_ship_2(ship1, ship2, ship3, ship4, ship5, ship6);
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
			move_ship_3(ship1, ship2, ship3);
			return;
		}
	}
	else if (!ship2.ship_exist())
	{
		if (ship2.ship_x_y(x, y))
		{
			ship2.deleteShip();
			move_ship_3(ship1, ship2, ship3);
			return;
		}
	}
	else if (!ship3.ship_exist())
	{
		if (ship3.ship_x_y(x, y))
		{
			ship3.deleteShip();
			move_ship_3(ship1, ship2, ship3);
			return;
		}
	}
}


int Ship::count_ship;
int Ship::count_ship_1;
int Ship::count_ship_2;
int Ship::count_ship_3;
int Ship::count_ship_4;

