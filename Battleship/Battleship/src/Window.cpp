#include "Window.h"


GameWindow::GameWindow()
{
		//size window
		VideoMode videoMode;
		videoMode.height = 600;
		videoMode.width = 1000;

		//name and setings window
		this->window = new RenderWindow(videoMode, "Batle Ship", Style::Titlebar | Style::Close);

		batlefield = new Battlefield(40, 70, "Player");
		batlefieldEnemy = new Battlefield(650, 70, "Enemy");
}



GameWindow::~GameWindow()
{
	delete window;
	delete batlefield;
	delete batlefieldEnemy;
}


void GameWindow::clearWindow()
{
	window->clear(Color(30, 30, 30));
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
	/*Font arial;
	arial.loadFromFile("fonts/arial.ttf");
	window.serFont(arial);
	window.drawSetStart();*/

}

