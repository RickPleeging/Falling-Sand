#include "pch.h"
#include "Falling Sand.h"


void handleinput(std::vector<std::vector<int>>& matrix, sf::RenderWindow& window)
{

	//swap selcted material
	static int selectedID = 1;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
	{
		selectedID = 1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
	{
		selectedID = 2;
	}

	//TODO
	//implement code to increase draw size (using for loop)


	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		sf::Vector2i mousePos = sf::Mouse::getPosition(window) / pixelsize;


		if (mousePos.y >= 0 && mousePos.y < worldheight && mousePos.x < worldwidth && mousePos.x >= 0)
		{
			matrix[mousePos.y][mousePos.x] = selectedID;
			

			// std::cout << "x: " << mousePos.x << " y: " << mousePos.y << "\n"; //debug position
		}

	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) //reset screen
	{
		for (int i = worldheight - 1; i >= 0; i--)
			for (int j = worldwidth - 1; j >= 0; j--)
				matrix[i][j] = 0;
	}


}
