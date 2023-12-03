#include "pch.h"

void mainmenu() {

	sf::RenderWindow menu(sf::VideoMode(640, 480), "Menu", sf::Style::Close);
	menu.setFramerateLimit(60);

	while (menu.isOpen())
	{

		sf::Event eventm;
		while (menu.pollEvent(eventm))
		{
			if (eventm.type == sf::Event::Closed)
				menu.close();

		}








	}


}