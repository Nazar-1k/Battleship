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
	void clickEvent(GameWindow& w);

private:
	Button* b_menu;

	//Main menu
	Button* b_start;
	Button* b_info;
	Button* b_exit;
	
	//Set position
	Button* b_auto;
	Button* b_manual_spacation;
	Button* b_back;


	//Set manual spacation position
	Button* b_clear;
	Button* b_save;

	Button* b_next;

	Button* b_back_m;

	//Battle menu
	sf::Text info_shot_text;
	Button* b_restart;
	Button* b_exit_to_menu;

	//menu type: 0 - start menu, 1 - set menu, 2 - set menu manual_spacation, 3 - set menu auto,   4 - battle menu
	static int menu_type;
};

