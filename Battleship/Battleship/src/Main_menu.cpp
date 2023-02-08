#include "Main_menu.h"


Main_menu::Main_menu()
{
	menu_type = 3;

	b_menu = new Button("Menu", { 220,100 }, 80, sf::Color(30, 30, 30), sf::Color::White);

#pragma region Main_menu
	b_start = new Button("Start", { 120,60 }, 50, sf::Color(40, 40, 40), sf::Color::White);
	b_record = new Button("Record", { 170,60 }, 50, sf::Color(40, 40, 40), sf::Color::White);
	b_exit = new Button("Exit", { 100, 60 }, 50, sf::Color(40, 40, 40), sf::Color::White);
#pragma endregion

#pragma region Set_menu
	b_auto = new Button("Auto Set", { 170,60 }, 40, sf::Color(40, 40, 40), sf::Color::White);
	b_manual_spacation = new Button("Manual Specation", { 260,60 }, 30, sf::Color(40, 40, 40), sf::Color::White);
	b_back = new Button("Back", { 100, 60 }, 40, sf::Color(40, 40, 40), sf::Color::White);
#pragma endregion

#pragma region Battle_menu
	info_shot_text;
	b_restart = new Button("Restart", { 150,60 }, 40, sf::Color(40, 40, 40), sf::Color::White);
	b_exit_to_menu = new Button("Exit to menu", { 230, 60 }, 40, sf::Color(40, 40, 40), sf::Color::White);
#pragma endregion
}

Main_menu::~Main_menu()
{
	delete b_menu;
	
	delete b_start;
	delete b_exit;
	delete b_record;
	
	delete b_auto;
	delete b_manual_spacation;
	delete b_back;

	delete b_restart;
	delete b_exit_to_menu;


}

void Main_menu::set_font(sf::Font& arial)
{
	b_menu->sentFont(arial);

	//Main menu
	b_start->sentFont(arial);
	b_record->sentFont(arial);
	b_exit->sentFont(arial);

	//Set menu
	b_auto->sentFont(arial);
	b_manual_spacation->sentFont(arial);
	b_back->sentFont(arial);

	//Battle_menu
	info_shot_text.setFont(arial);
	b_restart->sentFont(arial);
	b_exit_to_menu->sentFont(arial);
}

void Main_menu::set_position()
{
	b_menu->setPosition({ 385 , 30 });

#pragma region Main_menu_position
	b_start->setPosition({ 435 , 150 });
	b_record->setPosition({ 410 , 240 });
	b_exit->setPosition({ 445 , 330 });
#pragma endregion

#pragma region Set_menu_position
	b_auto->setPosition({ 410 , 150 });
	b_manual_spacation->setPosition({ 365 , 240 });
	b_back->setPosition({ 445 , 330 });
#pragma endregion

#pragma region Battle_menu_position
	b_restart->setPosition({ 420 , 240 });
	b_exit_to_menu->setPosition({ 380 , 330 });
#pragma endregion

}

void Main_menu::draw(GameWindow& w)
{
	sf::Font arial;
	arial.loadFromFile("fonts/arial.ttf");
	set_font(arial);

	set_position();
	
#pragma region Hower

	#pragma region Main menu
		if (b_start->isMouseOver(*w.window))
			b_start->setBackColor(sf::Color(64, 64, 90));
		else
			b_start->setBackColor(sf::Color(40, 40, 40));

		if (b_exit->isMouseOver(*w.window))
			b_exit->setBackColor(sf::Color(64, 64, 90));
		else
			b_exit->setBackColor(sf::Color(40, 40, 40));
	
		if (b_record->isMouseOver(*w.window))
			b_record->setBackColor(sf::Color(64, 64, 90));
		else
			b_record->setBackColor(sf::Color(40, 40, 40));
	#pragma endregion

	#pragma region Setposition
		if (b_auto->isMouseOver(*w.window))
			b_auto->setBackColor(sf::Color(64, 64, 90));
		else
			b_auto->setBackColor(sf::Color(40, 40, 40));

		if (b_manual_spacation->isMouseOver(*w.window))
			b_manual_spacation->setBackColor(sf::Color(64, 64, 90));
		else
			b_manual_spacation->setBackColor(sf::Color(40, 40, 40));

		if (b_back->isMouseOver(*w.window))
			b_back->setBackColor(sf::Color(64, 64, 90));
		else
			b_back->setBackColor(sf::Color(40, 40, 40));
	#pragma endregion

	#pragma region Battlemenu
		if (b_restart->isMouseOver(*w.window))
			b_restart->setBackColor(sf::Color(64, 64, 90));
		else
			b_restart->setBackColor(sf::Color(40, 40, 40));

		if (b_exit_to_menu->isMouseOver(*w.window))
			b_exit_to_menu->setBackColor(sf::Color(64, 64, 90));
		else
			b_exit_to_menu->setBackColor(sf::Color(40, 40, 40));
	#pragma endregion

#pragma endregion

#pragma region Draw_elements_menu
	b_menu->drawTo(*w.window);
	//Main menu
	if (menu_type == 1)
	{
		b_start->drawTo(*w.window);
		b_record->drawTo(*w.window);
		b_exit->drawTo(*w.window);
	}
	//Set position
	else if (menu_type == 2)
	{
		b_auto->drawTo(*w.window);
		b_manual_spacation->drawTo(*w.window);
		b_back->drawTo(*w.window);
	}
	//Batle menu
	else if (menu_type == 3)
	{
		w.window->draw(info_shot_text);
		b_restart->drawTo(*w.window);
		b_exit_to_menu->drawTo(*w.window);
	}
#pragma endregion

}

