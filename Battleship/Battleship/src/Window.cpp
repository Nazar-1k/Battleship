#include "Window.h"


GameWindow::GameWindow()
{
		//size window
	sf::VideoMode videoMode;
	videoMode.height = 600;
	videoMode.width = 1000;

	//name and setings window
	this->window = new sf::RenderWindow(videoMode, "Batle Ship", sf::Style::Titlebar | sf::Style::Close);

	batlefield = new Battlefield(40, 70, "Player");
	batlefieldEnemy = new Battlefield(650, 70, "Enemy");
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
		/*batlefield->clickEvent(*this);*/

	/*	batlefield->clickEvent_(*this);*/
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
