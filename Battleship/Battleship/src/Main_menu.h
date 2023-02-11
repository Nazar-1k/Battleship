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

	bool get_auto() { return auto_b; }
	void set_auto(bool auto_b);

	bool get_manual_spacation() { return manual_spacation_b; }

	bool get_clear() { return clear_b; }
	void set_clear(bool clear_b);
	bool get_save() { return save_b; }
	void set_save(bool save_b) { this->save_b = save_b; }

	bool get_next() { return next_b; }

	bool get_restart() { return restart_b; }

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

	bool auto_b;
	bool manual_spacation_b;

	//Set manual spacation position
	Button* b_clear;
	Button* b_save;

	bool clear_b;
	bool save_b;

	Button* b_next;
	bool next_b;

	Button* b_back_m;

	//Battle menu
	sf::Text info_shot_text;
	Button* b_restart;
	Button* b_exit_to_menu;

	bool restart_b;


	//menu type: 0 - start menu, 1 - set menu, 2 - set menu manual_spacation, 3 - set menu auto,   4 - battle menu
	static int menu_type;
};

