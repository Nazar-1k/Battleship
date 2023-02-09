#include "Main_menu.h"


Main_menu::Main_menu()
{
	b_menu = new Button("Menu", { 220,100 }, 80, sf::Color(30, 30, 30), sf::Color::White);

#pragma region Main_menu
	b_start = new Button("Start", { 120,60 }, 50, sf::Color(40, 40, 40), sf::Color::White);
	b_info = new Button("Info", { 110,60 }, 50, sf::Color(40, 40, 40), sf::Color::White);
	b_exit = new Button("Exit", { 100, 60 }, 50, sf::Color(40, 40, 40), sf::Color::White);
#pragma endregion

#pragma region Set_menu
	b_auto = new Button("Auto Set", { 170,60 }, 40, sf::Color(40, 40, 40), sf::Color::White);
	b_manual_spacation = new Button("Manual Specation", { 260,60 }, 30, sf::Color(40, 40, 40), sf::Color::White);
	b_back = new Button("Back", { 100, 60 }, 40, sf::Color(40, 40, 40), sf::Color::White);


#pragma endregion

#pragma region Set_menu_manual_spacation_and_auto
	b_clear = new Button("Clear", { 120,60 }, 50, sf::Color(40, 40, 40), sf::Color::White);
	b_next = new Button("Next", { 120,60 }, 50, sf::Color(40, 40, 40), sf::Color::White);
	b_save = new Button("Save", { 120,60 }, 50, sf::Color(40, 40, 40), sf::Color::White);
	b_back_m = new Button("Back", { 120,60 }, 50, sf::Color(40, 40, 40), sf::Color::White);
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
	delete b_info;
	
	delete b_auto;
	delete b_manual_spacation;
	delete b_back;

	delete b_restart;
	delete b_exit_to_menu;

	delete b_back_m;
	delete b_clear;
	delete b_save;
	delete b_next;
}

void Main_menu::set_font(sf::Font& arial)
{
	b_menu->sentFont(arial);

	//Main menu
	b_start->sentFont(arial);
	b_info->sentFont(arial);
	b_exit->sentFont(arial);

	//Set menu
	b_auto->sentFont(arial);
	b_manual_spacation->sentFont(arial);
	b_back->sentFont(arial);

	//Set Set_menu_manual_spacation_and_autou
	b_clear->sentFont(arial);
	b_next->sentFont(arial);
	b_save->sentFont(arial);
	b_back_m->sentFont(arial);

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
	b_info->setPosition({ 440 , 240 });
	b_exit->setPosition({ 445 , 330 });
#pragma endregion

#pragma region Set_menu_position
	b_auto->setPosition({ 410 , 150 });
	b_manual_spacation->setPosition({ 365 , 240 });
	b_back->setPosition({ 445 , 330 });
#pragma endregion

#pragma region Set_menu_manual_spacation_and_auto
	b_clear->setPosition({ 440 , 150 });
	b_next->setPosition({ 440 , 150 });
	b_save->setPosition({ 440 , 240 });
	b_back_m->setPosition( { 440 , 330 });
#pragma endregion

#pragma region Battle_menu_position
	b_restart->setPosition({ 420 , 240 });
	b_exit_to_menu->setPosition({ 380 , 330 });
#pragma endregion

}

void Main_menu::clickEvent(GameWindow& w)
{
	if (w.event.type == sf::Event::MouseButtonReleased)
	{
		//Main Menu
		if (menu_type == 0)
		{
			if (b_start->isMouseOver(*w.window))
				menu_type = 1;

			else if (b_info->isMouseOver(*w.window))
				std::cout << "Somethink";
				
			else if (b_exit->isMouseOver(*w.window))
				w.window->close();
		}
		//Set Menu
		else if (menu_type == 1)
		{
			if (b_auto->isMouseOver(*w.window))
				menu_type = 3;

			else if (b_manual_spacation->isMouseOver(*w.window))
				menu_type = 2;

			else if (b_back->isMouseOver(*w.window))
				menu_type = 0;
		}
		//Set Menu manual_spacation
		else if (menu_type == 2)
		{
			if (b_clear->isMouseOver(*w.window))
			{
				std::cout << "clear";

			}

			else if (b_save->isMouseOver(*w.window))
			{
				std::cout << "Save";
				menu_type = 4;
			}

			else if (b_back_m->isMouseOver(*w.window))
				menu_type = 1;
		}

		//Set Menu auto
		else if (menu_type == 3)
		{
			if (b_next->isMouseOver(*w.window))
			{
				std::cout << "Next";
			}

			else if (b_save->isMouseOver(*w.window))
			{
				std::cout << "Save";
				menu_type = 4;
			}

			else if (b_back_m->isMouseOver(*w.window))
				menu_type = 1;
		}

		//Battle menu
		else if (menu_type == 4)
		{
			//text////////////////////

			if (b_restart->isMouseOver(*w.window))
				std::cout << "Restart";

			else if (b_exit_to_menu->isMouseOver(*w.window))
				menu_type = 0;
		}
	}	
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
	
		if (b_info->isMouseOver(*w.window))
			b_info->setBackColor(sf::Color(64, 64, 90));
		else
			b_info->setBackColor(sf::Color(40, 40, 40));
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

#pragma region Setposition_menu_manual_spacation_and_auto
		if (b_clear->isMouseOver(*w.window))
			b_clear->setBackColor(sf::Color(64, 64, 90));
		else
			b_clear->setBackColor(sf::Color(40, 40, 40));

		if (b_save->isMouseOver(*w.window))
			b_save->setBackColor(sf::Color(64, 64, 90));
		else
			b_save->setBackColor(sf::Color(40, 40, 40));

		if (b_next->isMouseOver(*w.window))
			b_next->setBackColor(sf::Color(64, 64, 90));
		else
			b_next->setBackColor(sf::Color(40, 40, 40));

		if (b_back_m->isMouseOver(*w.window))
			b_back_m->setBackColor(sf::Color(64, 64, 90));
		else
			b_back_m->setBackColor(sf::Color(40, 40, 40));

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
	if (menu_type == 0)
	{
		b_start->drawTo(*w.window);
		b_info->drawTo(*w.window);
		b_exit->drawTo(*w.window);
	}
	//Set position
	else if (menu_type == 1)
	{
		b_auto->drawTo(*w.window);
		b_manual_spacation->drawTo(*w.window);
		b_back->drawTo(*w.window);
	}
	//set manual spacation position
	else if (menu_type == 2)
	{
		b_clear->drawTo(*w.window);
		b_save->drawTo(*w.window);
		b_back_m->drawTo(*w.window);
	}
	//set auto position
	else if (menu_type == 3)
	{
		b_next->drawTo(*w.window);
		b_save->drawTo(*w.window);
		b_back_m->drawTo(*w.window);
	}
	//Batle menu
	else if (menu_type == 4)
	{
		w.window->draw(info_shot_text);
		b_restart->drawTo(*w.window);
		b_exit_to_menu->drawTo(*w.window);
	}
#pragma endregion

}
int Main_menu::menu_type;