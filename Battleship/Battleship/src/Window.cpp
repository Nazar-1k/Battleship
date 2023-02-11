#include "Window.h"


GameWindow::GameWindow()
{
		//size window
	sf::VideoMode videoMode;
	videoMode.height = 600;
	videoMode.width = 1000;

	//name and setings window
	this->window = new sf::RenderWindow(videoMode, "Batle Ship", sf::Style::Titlebar | sf::Style::Close);

	batlefield = new Battlefield(40, 70, "Player", false);
	batlefieldEnemy = new Battlefield(650, 70, "Enemy", true);
	menu = new Main_menu;
}



GameWindow::~GameWindow()
{
	delete window;
	delete batlefield;
	delete batlefieldEnemy;
	delete menu;
}


void GameWindow::clearWindow()
{
	window->clear(sf::Color(30, 30, 30));
}

void GameWindow::displayWindow()
{
	window->display();
}

bool GameWindow::isOpenWindow()
{
	return window->isOpen();
}

void GameWindow::pollEventWindow()
{
	while (window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window->close();

		menu->clickEvent(*this);
		//Ather event
		if (menu->get_manual_spacation())
		{
			batlefield->clickEvent(*this);
		}
		if (menu->get_auto())
		{
			batlefield->clear();
			batlefield->autoSet();
			menu->set_auto(false);
		}

		if (menu->get_clear())
		{
			batlefield->clear();
			menu->set_clear(false);
		}
		if (menu->get_save())
		{
			batlefieldEnemy->autoSet();
			Ship::set_CountShip(Ship::get_CountShip() - 10);

			Ship::set_CountShip_1(Ship::get_CountShip_1() - 4);
			Ship::set_CountShip_2(Ship::get_CountShip_2() - 3);
			Ship::set_CountShip_3(Ship::get_CountShip_3() - 2);
			Ship::set_CountShip_4(Ship::get_CountShip_4() - 1);
			menu->set_save(false);
		}


	}
}

void GameWindow::drawWindowObjects()
{

	batlefield->drawBatlefield(*this);
	batlefieldEnemy->drawBatlefield(*this);
	//drow menu
	menu->draw(*this);

	/*Font arial;
	arial.loadFromFile("fonts/arial.ttf");
	window.serFont(arial);
	window.drawSetStart();*/

}
