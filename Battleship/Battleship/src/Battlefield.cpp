#include "Battlefield.h"

Battlefield::Battlefield()
	:x(0), y(0), count_field(0)
{
	initField(x, y);
	initBattlefield(x - 2, y - 2);
	initeText(x, y, "NO_NAME");
	initeShipMenu(x, y);
}

Battlefield::Battlefield(float x, float y, sf::String string)
	:x(x), y(y), count_field(0)
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
		delete[] field[i];
		delete[] fieldMenu[i];
	}
	delete[] number;
	delete[] ABC;
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
	ubdateShip1(ship1_1);

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
	number = new sf::Text[11];

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
		//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		for (int x = 0; x < 10; x++)
		{
			for (int y = 0; y < 10; y++)
			{
				if (field[x][y].cursorIsGiven == true and count_field < 20 and field[x][y].noShip == true and field[x][y].ship == false)
				{
					field[x][y].ship = true;
					count_field++;
					/*std::cout << "Count ship = "<<Ship::get_CountShip() << std::endl;*/

					#pragma region All_options_for_creating_ship
										//All_options_for_creating_ship 
										// 
										//[ ] - single deck ship
										//[][] - double deck ship
										//[][][] - three deck ship
										//[][][][] - four deck ship
										//[X] - The place where we add the deck
					// The coordinates of the ship are always from the right if it is horizontal, and from above if it is vertical


					#pragma region 1-deck

					//1 - deck
					// X
										bool option_creat_1_deck_ship{ field[x][y].ship == true };

					#pragma endregion

					#pragma region 2-deck

										//2 - deck vertically
										// []X
										bool first_option_creat_2_deck_ship_vertically{ x >= 1 and field[x][y].ship == true and field[x - 1][y].ship == true };
										// X[]
										bool second_option_creat_2_deck_ship_vertically{ x <= 8 and field[x][y].ship == true and field[x + 1][y].ship == true };

										//2 - deck horizontally
										// [ ]
										// [X]
										bool first_option_creat_2_deck_ship_horizontally{ y >= 1 and field[x][y].ship == true and field[x][y - 1].ship == true };
										// [X]
										// [ ]
										bool second_option_creat_2_deck_ship_horizontally{ y <= 8 and field[x][y].ship == true and field[x][y + 1].ship == true };

					#pragma endregion

					#pragma region 3-deck

										//3 - deck vertically
										// [][]X
										bool first_option_creat_3_deck_ship_vertically{ x >= 2 and field[x][y].ship == true and field[x - 1][y].ship == true and field[x - 2][y].ship == true };
										// X[][]
										bool second_option_creat_3_deck_ship_vertically{ x <= 7 and field[x][y].ship == true and field[x + 1][y].ship == true and field[x + 2][y].ship == true };
										// []X[]
										bool third_option_creat_3_deck_ship_vertically{ x >= 1 and x <= 8 and field[x][y].ship == true and field[x - 1][y].ship == true and field[x + 1][y].ship == true };


										//3 - deck horizontally
										// [X]
										// [ ]
										// [ ]
										bool first_option_creat_3_deck_ship_horizontally{ y <= 7 and field[x][y].ship == true and field[x][y + 1].ship == true and field[x][y + 2].ship == true };
										// [ ]
										// [X]
										// [ ]
										bool second_option_creat_3_deck_ship_horizontally{ y >= 1 and y <= 8 and field[x][y].ship == true and field[x][y - 1].ship == true and field[x][y + 1].ship == true };
										// [ ]
										// [ ]
										// [X]
										bool third_option_creat_3_deck_ship_horizontally{ y >= 2 and field[x][y].ship == true and field[x][y - 1].ship == true and field[x][y - 2].ship == true };

					#pragma endregion

					#pragma region 4-deck

										//4 - deck vertically
										// [][][]X
										bool first_option_creat_4_deck_ship_vertically{ x >= 3 and field[x][y].ship == true and field[x - 1][y].ship == true and field[x - 2][y].ship == true and field[x - 3][y].ship == true };
										// X[][][]
										bool second_option_creat_4_deck_ship_vertically{ x <= 6 and field[x][y].ship == true and field[x + 1][y].ship == true and field[x + 2][y].ship == true and field[x + 3][y].ship == true };
										// []X[][]
										bool third_option_creat_4_deck_ship_vertically{ x >= 1 and x <= 7 and field[x][y].ship == true and field[x - 1][y].ship == true and field[x + 1][y].ship == true and field[x + 2][y].ship == true };
										// [][]X[]
										bool fourth_option_creat_4_deck_ship_vertically{ x >= 2 and x <= 8 and field[x][y].ship == true and field[x - 1][y].ship == true and field[x - 2][y].ship == true and field[x + 1][y].ship == true };

										//4 - deck horizontally
										// [X]
										// [ ]
										// [ ]
										// [ ]
										bool first_option_creat_4_deck_ship_horizontally{ y <= 6 and field[x][y].ship == true and field[x][y + 1].ship == true and field[x][y + 2].ship == true and field[x][y + 3].ship == true };
										// [ ]
										// [X]
										// [ ]
										// [ ]
										bool second_option_creat_4_deck_ship_horizontally{ y >= 1 and y <= 7 and field[x][y].ship == true and field[x][y - 1].ship == true and field[x][y + 1].ship == true and field[x][y + 2].ship == true };
										// [ ]
										// [ ]
										// [X]
										// [ ]
										bool third_option_creat_4_deck_ship_horizontally{ y >= 2 and y <= 8 and field[x][y].ship == true and field[x][y - 1].ship == true and field[x][y - 2].ship == true and field[x][y + 1].ship == true };
										// [ ]
										// [ ]
										// [ ]
										// [X]
										bool fourth_option_creat_4_deck_ship_horizontally{ y >= 3 and field[x][y].ship == true and field[x][y - 1].ship == true and field[x][y - 2].ship == true and field[x][y - 3].ship == true };

					#pragma endregion

					#pragma endregion

					#pragma region Add_Ship

					//adding 4 deck ship horizontally
					if (first_option_creat_4_deck_ship_horizontally or
						second_option_creat_4_deck_ship_horizontally or
						third_option_creat_4_deck_ship_horizontally or
						fourth_option_creat_4_deck_ship_horizontally and
						Ship::get_CountShip_4() < 1)
					{
						/*std::cout << "Creat 4 Ship novertical" << std::endl;*/
					#pragma region remove_ship
						if (first_option_creat_4_deck_ship_horizontally)
						{
							Ship::delete_used_ship(x, y + 1, ship3_1, ship3_2, ship3_3);
						}
						else if (second_option_creat_4_deck_ship_horizontally)
						{
							Ship::delete_used_ship(x, y - 1, ship1_1, ship1_2, ship1_3, ship1_4, ship1_5, ship1_6, ship1_7, ship1_8, ship1_9, ship1_10, ship1_11, ship1_12, ship1_13);
							Ship::delete_used_ship(x, y + 1, ship2_1, ship2_2, ship2_3, ship2_4, ship2_5, ship2_6);
						}
						else if (third_option_creat_4_deck_ship_horizontally)
						{
							Ship::delete_used_ship(x, y + 2, ship2_1, ship2_2, ship2_3, ship2_4, ship2_5, ship2_6);
							Ship::delete_used_ship(x, y - 1, ship1_1, ship1_2, ship1_3, ship1_4, ship1_5, ship1_6, ship1_7, ship1_8, ship1_9, ship1_10, ship1_11, ship1_12, ship1_13);
						}
						else if (fourth_option_creat_4_deck_ship_horizontally)
						{
							Ship::delete_used_ship(x, y - 3, ship3_1, ship3_2, ship3_3);
						}
					#pragma endregion

					#pragma region subtract_number_from_the_removed_boats
						if (first_option_creat_4_deck_ship_horizontally or fourth_option_creat_4_deck_ship_horizontally)
						{
							Ship::set_CountShip_3(Ship::get_CountShip_3() - 1);
						}
						else if (second_option_creat_4_deck_ship_horizontally or third_option_creat_4_deck_ship_horizontally)
						{
							Ship::set_CountShip_1(Ship::get_CountShip_1() - 1);
							Ship::set_CountShip_2(Ship::get_CountShip_2() - 1);
						}
					#pragma endregion

					#pragma region setPosition

						if (fourth_option_creat_4_deck_ship_horizontally)
							y -= 3;
						else if (third_option_creat_4_deck_ship_horizontally)
							y -= 2;
						else if (second_option_creat_4_deck_ship_horizontally)
							y -= 1;

					#pragma endregion

					#pragma region creatShip

						if (ship4.ship_exist())
						{
							ship4.creatShip(x, y, false, 4);
						}
					#pragma endregion

						return;
					}


					//adding 3 deck ship horizontally
					else if (first_option_creat_3_deck_ship_horizontally or
						second_option_creat_3_deck_ship_horizontally or
						third_option_creat_3_deck_ship_horizontally and
						Ship::get_CountShip_3() < 4)
					{
						/*std::cout << "Creat 3 Ship novertical" << std::endl;*/

						#pragma region remove_ship
						
						if (first_option_creat_3_deck_ship_horizontally)
						{
							Ship::delete_used_ship(x, y + 1, ship2_1, ship2_2, ship2_3, ship2_4, ship2_5, ship2_6);
						}
						else if (second_option_creat_3_deck_ship_horizontally)
						{
							Ship::delete_used_ship(x, y + 1, ship1_1, ship1_2, ship1_3, ship1_4, ship1_5, ship1_6, ship1_7, ship1_8, ship1_9, ship1_10, ship1_11, ship1_12, ship1_13);
							Ship::delete_used_ship(x, y - 1, ship1_1, ship1_2, ship1_3, ship1_4, ship1_5, ship1_6, ship1_7, ship1_8, ship1_9, ship1_10, ship1_11, ship1_12, ship1_13);
						}
						else if (third_option_creat_3_deck_ship_horizontally)
						{
							Ship::delete_used_ship(x, y - 2, ship2_1, ship2_2, ship2_3, ship2_4, ship2_5, ship2_6);
						}

						#pragma endregion

						#pragma region subtract_number_from_the_removed_boats

						if (first_option_creat_3_deck_ship_horizontally or third_option_creat_3_deck_ship_horizontally)
						{
							Ship::set_CountShip_2(Ship::get_CountShip_2() - 1);
						}
						else if (second_option_creat_3_deck_ship_horizontally)
						{
							Ship::set_CountShip_1(Ship::get_CountShip_1() - 2);
						}

						#pragma endregion

						#pragma region setPosition

						if (third_option_creat_3_deck_ship_horizontally)
							y -= 2;
						else if (second_option_creat_3_deck_ship_horizontally)
							y -= 1;

						#pragma endregion

						#pragma region creatShip

						if (ship3_1.ship_exist())
						{
							ship3_1.creatShip(x, y, false, 3);
						}

						else if (ship3_2.ship_exist())
						{
							ship3_2.creatShip(x, y, false, 3);
						}

						else if (ship3_3.ship_exist())
						{
							ship3_3.creatShip(x, y, false, 3);
						}

						#pragma endregion

						return;
					}


					//adding 2 deck ship horizontally
					else if (first_option_creat_2_deck_ship_horizontally or
						second_option_creat_2_deck_ship_horizontally and
						Ship::get_CountShip_2() < 6)
					{
						/*std::cout << "Creat 2 Ship novertical" << std::endl;*/

						#pragma region remote_ship

						if (first_option_creat_2_deck_ship_horizontally)
						{
						Ship::delete_used_ship(x, y - 1, ship1_1, ship1_2, ship1_3, ship1_4, ship1_5, ship1_6, ship1_7, ship1_8, ship1_9, ship1_10, ship1_11, ship1_12, ship1_13);
						}
						if (second_option_creat_2_deck_ship_horizontally)
						{
						Ship::delete_used_ship(x, y + 1, ship1_1, ship1_2, ship1_3, ship1_4, ship1_5, ship1_6, ship1_7, ship1_8, ship1_9, ship1_10, ship1_11, ship1_12, ship1_13);
						}


						#pragma endregion

						#pragma region subtract_number_from_the_removed_boats
						
						Ship::set_CountShip_1(Ship::get_CountShip_1() - 1);

						#pragma endregion

						#pragma region SetPosition 
						if (first_option_creat_2_deck_ship_horizontally)
						{
							y -= 1;
						}
						#pragma endregion

						#pragma region creatShip
						if (ship2_1.ship_exist())
						{
							ship2_1.creatShip(x, y, false, 2);
						}

						else if (ship2_2.ship_exist())
						{
							ship2_2.creatShip(x, y, false, 2);
						}

						else if (ship2_3.ship_exist())
						{
							ship2_3.creatShip(x, y, false, 2);
						}

						else if (ship2_4.ship_exist())
						{
							ship2_4.creatShip(x, y, false, 2);
						}

						else if (ship2_5.ship_exist())
						{
							ship2_5.creatShip(x, y, false, 2);
						}

						else if (ship2_6.ship_exist())
						{
							ship2_6.creatShip(x, y, false, 2);
						}
						#pragma endregion

						return;
					}


					//adding 4 deck ship vertically
					else if (first_option_creat_4_deck_ship_vertically or
						second_option_creat_4_deck_ship_vertically or
						third_option_creat_4_deck_ship_vertically or
						fourth_option_creat_4_deck_ship_vertically and
						Ship::get_CountShip_4() < 1)
					{
						/*std::cout << "Creat 4 Ship vertical" << std::endl;*/

						#pragma region remove_ship
						if (first_option_creat_4_deck_ship_vertically)
						{
							Ship::delete_used_ship(x - 3, y, ship3_1, ship3_2, ship3_3);
						}
						else if (second_option_creat_4_deck_ship_vertically)
						{
							Ship::delete_used_ship(x + 1, y, ship3_1, ship3_2, ship3_3);
						}
						else if (third_option_creat_4_deck_ship_vertically)
						{
							Ship::delete_used_ship(x - 1, y, ship1_1, ship1_2, ship1_3, ship1_4, ship1_5, ship1_6, ship1_7, ship1_8, ship1_9, ship1_10, ship1_11, ship1_12, ship1_13);
							Ship::delete_used_ship(x + 1, y, ship2_1, ship2_2, ship2_3, ship2_4, ship2_5, ship2_6);
						}
						else if (fourth_option_creat_4_deck_ship_vertically)
						{
							Ship::delete_used_ship(x + 1, y, ship1_1, ship1_2, ship1_3, ship1_4, ship1_5, ship1_6, ship1_7, ship1_8, ship1_9, ship1_10, ship1_11, ship1_12, ship1_13);
							Ship::delete_used_ship(x - 2, y, ship2_1, ship2_2, ship2_3, ship2_4, ship2_5, ship2_6);
						}
						#pragma endregion

						#pragma region subtract_number_from_the_removed_boats
						if (first_option_creat_4_deck_ship_vertically or second_option_creat_4_deck_ship_vertically)
						{
							Ship::set_CountShip_3(Ship::get_CountShip_3() - 1);
						}
						else if (third_option_creat_4_deck_ship_vertically or fourth_option_creat_4_deck_ship_vertically)
						{
							Ship::set_CountShip_1(Ship::get_CountShip_1() - 1);
							Ship::set_CountShip_2(Ship::get_CountShip_2() - 1);
						}
						#pragma endregion
						
						#pragma region setPosition

						if (first_option_creat_4_deck_ship_vertically)
							x -= 3;
						else if (third_option_creat_4_deck_ship_vertically)
							x -= 1;
						else if (fourth_option_creat_4_deck_ship_vertically)
							x -= 2;

						#pragma endregion

						#pragma region creatShip

						if (ship4.ship_exist())
						{
							ship4.creatShip(x,y, true, 4);
						}
						#pragma endregion

						return;
					}


					//adding 3 deck ship vertically
					else if (first_option_creat_3_deck_ship_vertically or
						second_option_creat_3_deck_ship_vertically or
						third_option_creat_3_deck_ship_vertically and
						Ship::get_CountShip_3() < 3)
					{
						/*std::cout << "Creat 3 Ship vertical" << std::endl;*/

						#pragma region remove_ship
						if (first_option_creat_3_deck_ship_vertically)
						{
							Ship::delete_used_ship(x - 2, y, ship2_1, ship2_2, ship2_3, ship2_4, ship2_5, ship2_6);
						}
						else if (second_option_creat_3_deck_ship_vertically)
						{
							Ship::delete_used_ship(x + 1, y, ship2_1, ship2_2, ship2_3, ship2_4, ship2_5, ship2_6);
						}
						else if (third_option_creat_3_deck_ship_vertically)
						{
							Ship::delete_used_ship(x - 1, y, ship1_1, ship1_2, ship1_3, ship1_4, ship1_5, ship1_6, ship1_7, ship1_8, ship1_9, ship1_10, ship1_11, ship1_12, ship1_13);
							Ship::delete_used_ship(x + 1, y, ship1_1, ship1_2, ship1_3, ship1_4, ship1_5, ship1_6, ship1_7, ship1_8, ship1_9, ship1_10, ship1_11, ship1_12, ship1_13);
						}
						#pragma endregion

						#pragma region subtract_number_from_the_removed_boats
						if (first_option_creat_3_deck_ship_vertically or second_option_creat_3_deck_ship_vertically)
						{
							Ship::set_CountShip_2(Ship::get_CountShip_2() - 1);
						}
						else if (third_option_creat_3_deck_ship_vertically)
						{
							Ship::set_CountShip_1(Ship::get_CountShip_1() - 2);
						}
						#pragma endregion

						#pragma region setPosition
						
						if (first_option_creat_3_deck_ship_vertically)
							x -= 2;
						else if (third_option_creat_3_deck_ship_vertically)
							x -= 1;

						#pragma endregion

						#pragma region creatShip

						if (ship3_1.ship_exist())
						{
							ship3_1.creatShip(x, y, true, 3);
						}

						else if (ship3_2.ship_exist())
						{
							ship3_2.creatShip(x, y, true, 3);
						}

						else if (ship3_3.ship_exist())
						{
							ship3_3.creatShip(x, y, true, 3);
						}

						#pragma endregion

						return;
					}

					//adding 2 deck ship vertically
					else if (first_option_creat_2_deck_ship_vertically or
						second_option_creat_2_deck_ship_vertically and
						Ship::get_CountShip_2() < 6)
					{
						/*std::cout << "Creat 2 Ship vertical"<< std::endl;*/

						#pragma region remove_ship
						if (first_option_creat_2_deck_ship_vertically)
						{
							Ship::delete_used_ship(x - 1, y, ship1_1, ship1_2, ship1_3, ship1_4, ship1_5, ship1_6, ship1_7, ship1_8, ship1_9, ship1_10, ship1_11, ship1_12, ship1_13);
						}
						else if (second_option_creat_2_deck_ship_vertically)
						{
							Ship::delete_used_ship(x + 1, y, ship1_1, ship1_2, ship1_3, ship1_4, ship1_5, ship1_6, ship1_7, ship1_8, ship1_9, ship1_10, ship1_11, ship1_12, ship1_13);
						}


						#pragma endregion

						#pragma region subtract_number_from_the_removed_boats

						Ship::set_CountShip_1(Ship::get_CountShip_1() - 1);
						
						#pragma endregion

						#pragma region setPosition

						if (first_option_creat_2_deck_ship_vertically)
							x -= 1;

						#pragma endregion
						
						#pragma region creatShip
						if (ship2_1.ship_exist())
						{
							ship2_1.creatShip(x, y, true, 2);
						}

						else if (ship2_2.ship_exist())
						{
							ship2_2.creatShip(x, y, true, 2);
						}

						else if (ship2_3.ship_exist())
						{
							ship2_3.creatShip(x, y, true, 2);
						}

						else if (ship2_4.ship_exist())
						{
							ship2_4.creatShip(x, y, true, 2);
						}

						else if (ship2_5.ship_exist())
						{
							ship2_5.creatShip(x, y, true, 2);
						}

						else if (ship2_6.ship_exist())
						{
							ship2_6.creatShip(x, y, true, 2);
						}
						#pragma endregion

						return;
					}
					//adding 1 deck ship
					else if (option_creat_1_deck_ship and
						Ship::get_CountShip_1() <= 13)
					{
						/*std::cout << "Creat 1 Ship -> " << std::endl;*/
						#pragma region creatShip

						if (ship1_1.ship_exist())
						{
							ship1_1.creatShip(x, y, true, 1);
						}

						else if (ship1_2.ship_exist())
						{
							ship1_2.creatShip(x, y, true, 1);
						}

						else if (ship1_3.ship_exist())
						{
							ship1_3.creatShip(x, y, true, 1);
						}

						else if (ship1_4.ship_exist())
						{
							ship1_4.creatShip(x, y, true, 1);
						}

						else if (!ship1_5.ship_exist())
						{
							ship1_5.creatShip(x, y, true, 1);
						}

						else if (ship1_6.ship_exist())
						{
							ship1_6.creatShip(x, y, true, 1);
						}

						else if (ship1_7.ship_exist())
						{
							ship1_7.creatShip(x, y, true, 1);
						}

						else if (ship1_8.ship_exist())
						{
							ship1_8.creatShip(x, y, true, 1);
						}

						else if (ship1_9.ship_exist())
						{
							ship1_9.creatShip(x, y, true, 1);
						}

						else if (ship1_10.ship_exist())
						{
							ship1_10.creatShip(x, y, true, 1);
						}

						else if (ship1_11.ship_exist())
						{
							ship1_11.creatShip(x, y, true, 1);
						}

						else if (ship1_12.ship_exist())
						{
							ship1_12.creatShip(x, y, true, 1);
						}

						else if (ship1_13.ship_exist())
						{
							ship1_13.creatShip(x, y, true, 1);
						}
						#pragma endregion
						return;
					}
					#pragma endregion
				}
			}
		}
	}
}

void Battlefield::ubdateSetShip()
{
	ship4.Ship_info();
	for (int x = 0; x < 10; x++)
	{
		for (int y = 0; y < 10; y++)
		{
			#pragma region Prohibition_to_place_boats_diagonally
			//Prohibition to place boats diagonally
			if (x == 0 and y == 0 and field[x][y].ship == true)//upper right corner
			{
				field[x + 1][y + 1].noShip = false;
			}
			else if (x == 0 and y == 9 and field[x][y].ship == true)//upper left corner
			{
				field[x + 1][y - 1].noShip = false;
			}
			else if (x == 9 and y == 0 and field[x][y].ship == true)//lower right corner
			{
				field[x - 1][y + 1].noShip = false;
			}
			else if (x == 9 and y == 9 and field[x][y].ship == true)//lower left corner
			{
				field[x - 1][y - 1].noShip = false;
			}
			else if (x == 0 and field[x][y].ship == true)
			{
				field[x + 1][y + 1].noShip = false;
				field[x + 1][y - 1].noShip = false;
			}
			else if (x == 9 and field[x][y].ship == true)
			{
				field[x - 1][y - 1].noShip = false;
				field[x - 1][y + 1].noShip = false;
			}
			else if (field[x][y].ship == true)
			{
				field[x + 1][y + 1].noShip = false;

				field[x - 1][y - 1].noShip = false;

				field[x + 1][y - 1].noShip = false;

				field[x - 1][y + 1].noShip = false;
			}
			#pragma endregion
		}
	}
	
	if (Ship::get_CountShip_4() == 1)
	{
		#pragma region 4_ship

		if (ship4.getVerticalShip())
		{
			if (ship4.getx() > 0)
			{
				field[ship4.getx() - 1][ship4.gety()].noShip = false;

			}
			if (ship4.getx() < 6 and ship4.getx() >= 0)
			{
				field[ship4.getx() + 4][ship4.gety()].noShip = false;
			}
		}
		else 
		{
			if (ship4.gety() > 1)
				field[ship4.getx()][ship4.gety() - 1].noShip = false;

			if (ship4.gety() < 6 and ship4.gety() >= 0)
				field[ship4.getx()][ship4.gety() + 4].noShip = false;
		}
		#pragma endregion
	
		#pragma region 3_ship

		if (ship3_1.getVerticalShip())
		{
			if (ship3_1.getx() > 1)
			{
				field[ship3_1.getx() - 1][ship3_1.gety()].noShip = false;

			}
			if (ship3_1.getx() < 5 and ship3_1.getx() > 0)
			{
				field[ship3_1.getx() + 3][ship3_1.gety()].noShip = false;
			}
		}
		else
		{
			if (ship3_1.gety() > 0)
				field[ship3_1.getx()][ship3_1.gety() - 1].noShip = false;

			if (ship3_1.gety() < 5 and ship3_1.gety() > 0)
				field[ship3_1.getx()][ship3_1.gety() + 3].noShip = false;
		}

		if (ship3_2.getVerticalShip())
		{
			if (ship3_2.getx() > 0)
			{
				field[ship3_2.getx() - 1][ship3_2.gety()].noShip = false;

			}
			if (ship3_2.getx() < 5 and ship3_2.getx() > 0)
			{
				field[ship3_2.getx() + 3][ship3_2.gety()].noShip = false;
			}
		}
		else
		{
			if (ship3_2.gety() > 0)
				field[ship3_2.getx()][ship3_2.gety() - 1].noShip = false;

			if (ship3_2.gety() < 5 and ship3_2.gety() > 0)
				field[ship3_2.getx()][ship3_2.gety() + 3].noShip = false;
		}
		#pragma endregion
	}

	if ((Ship::get_CountShip_3() == 3 and Ship::get_CountShip_3() <= 3 ) or (Ship::get_CountShip_3() == 2 and Ship::get_CountShip_4() == 1 and Ship::get_CountShip_3() <= 3) )
	{
	
		#pragma region 2_ship
		 
		if (ship2_1.getVerticalShip())
		{
			if (ship2_1.getx() > 0)
			{
				field[ship2_1.getx() - 1][ship2_1.gety()].noShip = false;

			}
			if (ship2_1.getx() < 3 and ship2_1.getx() > 0)
			{
				field[ship2_1.getx() + 2][ship2_1.gety()].noShip = false;
			}
		}
		else
		{
			if (ship2_1.gety() > 0)
				field[ship2_1.getx()][ship2_1.gety() - 1].noShip = false;

			if (ship2_1.gety() < 3 and ship2_1.gety() > 0)
				field[ship2_1.getx()][ship2_1.gety() + 2].noShip = false;
		}

		if (ship2_2.getVerticalShip())
		{
			if (ship2_2.getx() > 0 )
			{
				field[ship2_2.getx() - 1][ship2_2.gety()].noShip = false;

			}
			if (ship2_2.getx() < 3 and ship2_2.getx() > 0)
			{
				field[ship2_2.getx() + 2][ship2_2.gety()].noShip = false;
			}
		}
		else
		{
			if (ship2_2.gety() > 0)
				field[ship2_2.getx()][ship2_2.gety() - 1].noShip = false;

			if (ship2_2.gety() < 3 and ship2_2.gety() > 0)
				field[ship2_2.getx()][ship2_2.gety() + 2].noShip = false;
		}

		if (ship2_3.getVerticalShip())
		{
			if (ship2_3.getx() > 0)
			{
				field[ship2_3.getx() - 1][ship2_3.gety()].noShip = false;

			}
			if (ship2_3.getx() < 3 and ship2_3.getx() > 0)
			{
				field[ship2_3.getx() + 2][ship2_3.gety()].noShip = false;
			}
		}
		else
		{
			if (ship2_3.gety() > 0)
				field[ship2_3.getx()][ship2_3.gety() - 1].noShip = false;

			if (ship2_3.gety() < 3 and ship2_3.gety() > 0)
				field[ship2_3.getx()][ship2_3.gety() + 2].noShip = false;
		}


		#pragma endregion
	}
	
	
	

}

void Battlefield::ubdateShip1(Ship& ship)
{


}
