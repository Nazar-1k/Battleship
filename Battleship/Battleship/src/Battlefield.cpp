#include "Battlefield.h"

Battlefield::Battlefield()
	:x(0), y(0)
{
	initField(x, y);
	initBattlefield(x - 2, y - 2);
	initeText(x, y, "NO_NAME");
	initeShipMenu(x, y);
}


Battlefield::Battlefield(float x, float y, sf::String string)
	:x(x), y(y)
{
	initField(x, y);
	initBattlefield(x - 2, y - 2);
	initeText(x, y, string);
	initeShipMenu(x, y);
}

Battlefield::~Battlefield()
{
	for (int i = 0; i < 10; i++)
	{
		delete [] field[i];
		delete [] fieldMenu[i];
	}
	delete [] number;
	delete [] ABC;
}

void Battlefield::setPosition(float x, float y)
{
	this->x = x;
	this->y = y;
}

void Battlefield::isMouseOver(GameWindow& w)
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (field[i][j].faield.getGlobalBounds().contains(static_cast<float>(sf::Mouse::getPosition(*w.window).x), static_cast<float>(sf::Mouse::getPosition(*w.window).y)))
			{
				field[i][j].cursorIsGiven = true;
			}
			else field[i][j].cursorIsGiven = false;
		}
	}
}

void Battlefield::setStringcoutShip(int count1, int count2, int count3, int count4)
{
	count1S_text.setString(std::to_string(count1));
	count2S_text.setString(std::to_string(count2));
	count3S_text.setString(std::to_string(count3));
	count4S_text.setString(std::to_string(count4));
}

//Set
void Battlefield::setFont(sf::Font& font)
{
	namePlaer.setFont(font);

	ShipType.setFont(font);
	CountShip.setFont(font);

	count2S_text.setFont(font);
	count3S_text.setFont(font);
	count4S_text.setFont(font);
	count1S_text.setFont(font);

	// Назви полів бою
	for (int i = 1; i < 11; i++)
	{
		ABC[i].setFont(font);
		number[i].setFont(font);
	}
}


 void Battlefield::drawBatlefield(GameWindow& w)
{

	 ubdateSetShip();

	sf::Font arial;
	arial.loadFromFile("fonts/arial.ttf");

	setStringcoutShip(Ship::get_CountShip_1(), Ship::get_CountShip_2(), Ship::get_CountShip_3(), Ship::get_CountShip_4());

	//Bground 
	isMouseOver(w);

	w.window->draw(battlefield);


	for (int x = 0; x < 10; x++)
	{
		//Text
		w.window->draw(namePlaer);
		w.window->draw(ShipType);
		w.window->draw(CountShip);

		setFont(arial);
		w.window->draw(ABC[x + 1]);
		w.window->draw(number[x + 1]);

		//Count Ship

		w.window->draw(count1S_text);
		w.window->draw(count2S_text);
		w.window->draw(count3S_text);
		w.window->draw(count4S_text);



		for (int y = 0; y < 10; y++)
		{
			//draw a Field of squares
			w.window->draw(field[x][y].faield);

			//Hover
			if (field[x][y].cursorIsGiven == true)
				field[x][y].faield.setFillColor(sf::Color(90, 190, 255));
			else 
				field[x][y].faield.setFillColor(sf::Color(64, 128, 160));
			
			//color ship
			if (field[x][y].ship == true)
				field[x][y].faield.setFillColor(sf::Color(72, 61, 139));
				

			//color noship zone
			else if (field[x][y].noShip == false)
			{
				field[x][y].faield.setFillColor(sf::Color(20, 100, 190));
			}
		}
	}

	// Draw the number of ships menu
	int count = 4;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < count; j++)
		{
			w.window->draw(fieldMenu[i][j].faield);
		}
		count--;
	}
}

 void Battlefield::initBattlefield(float x, float y)
 {
	 this->x = x;
	 this->y = y;
	 battlefield.setSize({ 322,322 });
	 battlefield.setPosition({ x, y });
	 battlefield.setFillColor(sf::Color::White);

 }

 void Battlefield::initField(float x, float y)
 {
	 //Allocation of memory for squares in a two-dimensional array
	 field = new Field * [10];
	 for (int i = 0; i < 10; i++)
	 {
		 field[i] = new Field[10];
	 }
	 y = this->y;
	 x = this->x;
	 for (int i = 0; i < 10; i++)
	 {
		 for (int j = 0; j < 10; j++)
		 {
			 field[i][j].x = static_cast<int>(x);
			 field[i][j].y = static_cast<int>(y);
			 field[i][j].faield.setPosition({ x, y });
			 field[i][j].cursorIsGiven = false;


			 x += 32;
		 }
		 y += 32;
		 x = this->x;
	 }
 }

 void Battlefield::initeText(float x, float y, sf::String string)
 {
	 count1S_text.setFillColor(sf::Color::White);
	 count1S_text.setCharacterSize(30);
	 count1S_text.setPosition({ x + 230, y + 485 });

	 count2S_text.setFillColor(sf::Color::White);
	 count2S_text.setCharacterSize(30);
	 count2S_text.setPosition({ x + 230, y + 445 });

	 count3S_text.setFillColor(sf::Color::White);
	 count3S_text.setCharacterSize(30);
	 count3S_text.setPosition({ x + 230, y + 405 });

	 count4S_text.setFillColor(sf::Color::White);
	 count4S_text.setCharacterSize(30);
	 count4S_text.setPosition({ x + 230, y + 365 });


	 namePlaer.setFillColor(sf::Color(90, 190, 255));
	 namePlaer.setCharacterSize(30);
	 namePlaer.setString(string);
	 namePlaer.setPosition({ x + 115, y - 70 });

	 ShipType.setFillColor(sf::Color::White);
	 ShipType.setCharacterSize(20);
	 ShipType.setString("Ship Type:");
	 ShipType.setPosition({ x + 20, y + 330 });

	 CountShip.setFillColor(sf::Color::White);
	 CountShip.setCharacterSize(20);
	 CountShip.setString("Count Ship:");
	 CountShip.setPosition({ x + 190, y + 330 });

	 //batlefield
	 ABC = new sf::Text[11];
	 number =  new sf::Text[11];

	 int nuber = 1;
	 char abc = 'A';

	 x = this->x - 20;
	 y = this->y - 26;
	 for (int i = 1; i < 11; i++)
	 {
		 /*std::cout << nuber << " " << abc << "  ";*/

		 ABC[i].setFillColor(sf::Color(90, 190, 255));
		 ABC[i].setCharacterSize(20);
		 ABC[i].setString(abc);
		 if (i == 9)
			 ABC[i].setPosition({ x + 32.f * i , y });
		 else
			 ABC[i].setPosition({ x + 32.f * i - 5, y });


		 number[i].setString(std::to_string(nuber));
		 number[i].setFillColor(sf::Color(90, 190, 255));
		 number[i].setCharacterSize(20);

		 if (i == 10)
			 number[i].setPosition({ x - 10, y + 32.f * i });
		 else
			 number[i].setPosition({ x, y + 32.f * i });


		 nuber++;
		 abc++;
	 }

 }

 void Battlefield::initeShipMenu(float x, float y)
 {
	 fieldMenu = (Field**) new Field * [4];
	 for (int i = 0; i < 4; i++)
	 {
		 fieldMenu[i] = new Field[4];
	 }
	 int count = 4;
	 y = y + 370;
	 for (int i = 0; i < 4; i++)
	 {
		 for (int j = 0; j < 4; j++)
		 {
			 fieldMenu[i][j].x = static_cast<int>(x);
			 fieldMenu[i][j].y = static_cast<int>(y);
			 fieldMenu[i][j].faield.setPosition({ x, y });
			 fieldMenu[i][j].cursorIsGiven = false;


			 x += 32;
			 count--;
		 }
		 y += 40;
		 x = this->x;
	 }
 }

 void Battlefield::clickEvent(GameWindow& w)
 {
	 
	 if (w.event.type == sf::Event::MouseButtonReleased)
	 {
		 for (int x = 0; x < 10; x++)
		 {
			 for (int y = 0; y < 10; y++)
			 {
				 if (field[x][y].cursorIsGiven == true and Ship::get_CountShip() < 20 and field[x][y].noShip == true and field[x][y].ship == false)
				 {
					 field[x][y].ship = true;
					 Ship::set_CountShip(Ship::get_CountShip() + 1);
					 
					//добавлення човна
					





					 std::cout << Ship::get_CountShip();
				 }
			 }
		 }
	 }
 }

 void Battlefield::ubdateSetShip()
 {
	
 }

 void Battlefield::ubdateShip1(Ship& ship)
 {
	 for (int x = 0; x < 10; x++)
	 {
		 for (int y = 0; y < 10; y++)
		 {
			#pragma region Prohibition_to_place_boats_diagonally
			 //Prohibition to place boats diagonally
			 if (ship.getx() == 0 and ship.gety() == 0)//upper right corner
			 {
				 field[ship.getx() + 1][ship.gety() + 1].noShip = false;
			 }
			 else if (ship.getx() == 0 and ship.gety() == 9)//upper left corner
			 {
				 field[ship.getx() + 1][ship.gety() - 1].noShip = false;
			 }
			 else if (ship.getx() == 9 and ship.gety() == 0)//lower right corner
			 {
				 field[ship.getx() - 1][ship.gety() + 1].noShip = false;
			 }
			 else if (ship.getx() == 9 and ship.gety() == 9)//lower left corner
			 {
				 field[ship.getx() - 1][ship.gety() - 1].noShip = false;
			 }
			 else if (ship.getx() == 0)
			 {
				 field[ship.getx() + 1][ship.gety() + 1].noShip = false;
				 field[ship.getx() + 1][ship.gety() - 1].noShip = false;
			 }
			 else if (ship.getx() == 9)
			 {
				 field[ship.getx() - 1][ship.gety() - 1].noShip = false;
				 field[ship.getx() - 1][ship.gety() + 1].noShip = false;
			 }
			 else
			 {
				 field[ship.getx() + 1][ship.gety() + 1].noShip = false;

				 field[ship.getx() - 1][ship.gety() - 1].noShip = false;

				 field[ship.getx() + 1][ship.gety() - 1].noShip = false;

				 field[ship.getx() - 1][ship.gety() + 1].noShip = false;
			 }
#pragma endregion

		 }
	 }

 }
