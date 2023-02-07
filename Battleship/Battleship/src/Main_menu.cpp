#include "Main_menu.h"


Main_menu::Main_menu()
{
	

	
	Set.setFillColor(sf::Color::White);
	Set.setCharacterSize(40);
	Set.setPosition({ 400, 100 });
	Set.setString("Start set:");

	
	Auto.setFillColor(sf::Color::White);
	Auto.setCharacterSize(25);
	Auto.setPosition({ 450, 200 });
	Auto.setString("Auto set");

	
	ManUAl_SpacatioN.setFillColor(sf::Color::White);
	ManUAl_SpacatioN.setCharacterSize(23);
	ManUAl_SpacatioN.setPosition({ 370, 230 });
	ManUAl_SpacatioN.setString("ManUAl SpacatioN Set");


	
	
}

void Main_menu::set_font(sf::Font& arial)
{
	

	Set.setFont(arial);
	Auto.setFont(arial);
	ManUAl_SpacatioN.setFont(arial);
}

void Main_menu::draw(GameWindow& w)
{
	

	sf::Font arial;
	arial.loadFromFile("fonts/arial.ttf");
	
	set_font(arial);

	w.window->draw(Set);
	w.window->draw(Auto);
	w.window->draw(ManUAl_SpacatioN);

	std::cout << "1";
}

