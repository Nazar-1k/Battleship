#pragma once
#include "Button.h"
#include "Window.h"

class Main_menu
{
public:
	friend class GameWindow;

	Main_menu();
	~Main_menu();

	void draw(GameWindow& w);
	void set_font(sf::Font& arial);
	void set_position();

private:
	Button* b_menu;

	//Main menu
	Button* b_start;
	Button* b_record;
	Button* b_exit;
	
	//Set position
	Button* b_auto;
	Button* b_manual_spacation;
	Button* b_back;

	//Battle menu
	sf::Text info_shot_text;
	Button* b_restart;
	Button* b_exit_to_menu;

	//menu type: 1 - start menu, 2 - set menu, 3 - battle menu
	int menu_type;
};

