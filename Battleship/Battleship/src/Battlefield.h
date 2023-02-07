#pragma once

#include "Field.h"
#include "Ship.h"
#include <SFML/Graphics.hpp>

#include "Window.h"
using namespace sf;

class Battlefield
{
	friend class GameWindow;

public:
	
	Battlefield();
	Battlefield(float x, float y, String string);

	~Battlefield();

	void setPosition(float x, float y);
	
	//Hower
	void isMouseOver(GameWindow& obj);


	//Set
	void setFont(Font& font);

	// Assign the number of ships to the text
	void setStringcoutShip(int count1, int count2, int count3, int count4);

	void drawBatlefield(GameWindow& w);
	
	/*void clickEvent(GameWindow& w);*/

	//void creatShip(int i, int j);

	//void updateShip();
		
private:

	float x;
	float y;

	//Text
	Text* ABC;
	Text* number;

	Text namePlaer;

	Text ShipType;
	Text CountShip;

	Text count1S_text;
	Text count2S_text;
	Text count3S_text;
	Text count4S_text;

	//Ñells on the field
	Field** field;
	Field** fieldMenu;

	//BackGround 
	RectangleShape battlefield;


	void initBattlefield(float x_, float y_);

	void initField(float x_, float y_);
	
	void initeText(float x_, float y_, String string);
	

	void initeShipMenu(float x_, float y_);

};
