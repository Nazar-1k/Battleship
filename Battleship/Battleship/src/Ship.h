#pragma once

#include "Field.h"


class Ship : Field
{
public:

	Ship();

	void setx(int x);
	void sety(int y);
	void setCount_deck(int count_deck);
	void setVerticalShip(bool verticalShip);
	void setShow(bool show);

	int getx() { return x; }
	int gety() { return y; }
	int getCount_deck() { return count_deck; }
	bool getVerticalShip() { return verticalShip; }
	bool getShow() { return show; }

	void creatShip(int x, int y, bool verticalShip, int count_deck);


	static int get_CountShip() { return count_ship; }

	static int get_CountShip_1() { return count_ship_1; }
	static int get_CountShip_2() { return count_ship_2; }
	static int get_CountShip_3() { return count_ship_3; }
	static int get_CountShip_4() { return count_ship_4; }

	static void set_CountShip(int count);

	static void set_CountShip_1(int count);
	static void set_CountShip_2(int count);
	static void set_CountShip_3(int count);
	static void set_CountShip_4(int count);


	void moveShip(Ship& ship);

	void Ship_info();

	bool ship_exist();

private:
	int x;
	int y;
	int count_deck;

	bool verticalShip;
	
	bool show;

	static int count_ship;

	static int count_ship_1;
	static int count_ship_2;
	static int count_ship_3;
	static int count_ship_4;
};
