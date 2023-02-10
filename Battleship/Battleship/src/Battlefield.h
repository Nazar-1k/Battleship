#pragma once

#include "Field.h"
#include "Ship.h"

#include "Window.h"


class Battlefield
{
	friend class GameWindow;

public:
	
	Battlefield();
	Battlefield(float x, float y, sf::String string);

	~Battlefield();

	void setPosition(float x, float y);
	
	//Hower
	void isMouseOver(GameWindow& obj);


	//Set
	void setFont(sf::Font& font);

	// Assign the number of ships to the text
	void setStringcoutShip(int count1, int count2, int count3, int count4);

	void drawBatlefield(GameWindow& w);
	
	void clickEvent(GameWindow& w);

	//updating boats when you put them on the field
	void ubdateSetShip();

	void ubdateShip1(Ship& ship);

	
		
private:

	float x;
	float y;

	//Text
	sf::Text* ABC;
	sf::Text* number;

	sf::Text namePlaer;

	sf::Text ShipType;
	sf::Text CountShip;

	sf::Text count1S_text;
	sf::Text count2S_text;
	sf::Text count3S_text;
	sf::Text count4S_text;

	//Ñells on the field
	Field** field;
	Field** fieldMenu;

	//BackGround 
	sf::RectangleShape battlefield;

	Ship ship1_1;
	Ship ship1_2;
	Ship ship1_3;
	Ship ship1_4;
	Ship ship1_5;
	Ship ship1_6;
	Ship ship1_7;
	Ship ship1_8;
	Ship ship1_9;
	Ship ship1_10;
	Ship ship1_11;
	Ship ship1_12;
	Ship ship1_13;

	Ship ship2_1;
	Ship ship2_2;
	Ship ship2_3;
	Ship ship2_4;
	Ship ship2_5;
	Ship ship2_6;

	Ship ship3_1;
	Ship ship3_2;
	Ship ship3_3;

	Ship ship4;



	void initBattlefield(float x_, float y_);

	void initField(float x_, float y_);
	
	void initeText(float x_, float y_, sf::String string);
	

	void initeShipMenu(float x_, float y_);

};
