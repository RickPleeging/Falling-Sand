#include "pch.h"
#include "Falling Sand.h"


void handleinput(std::vector<std::vector<int>>& matrix, sf::RenderWindow& window, sf::Event& event)
{

	//swap selcted material
	static int selectedID = 1;
	static int cursorsize = 1;
	static int cursorsize_max = 100 / pixelsize;
	static int increaserate = cursorsize_max / 5;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
	{
		selectedID = 1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
	{
		selectedID = 2;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) //reset screen
	{
		for (int i = worldheight - 1; i >= 0; i--)
			for (int j = worldwidth - 1; j >= 0; j--)
				matrix[i][j] = 0;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Hyphen))
	{
		if (cursorsize > 1)
		{
			cursorsize-= increaserate;
		
		}

	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Equal))
	{
		if (cursorsize < cursorsize_max)
			cursorsize+= increaserate;
	
	}



	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		sf::Vector2i mousePos = sf::Mouse::getPosition(window) / pixelsize;


		if (mousePos.y >= 0 && mousePos.y < worldheight && mousePos.x < worldwidth && mousePos.x >= 0)
		{
			for (int i = 0; i < cursorsize; i++)
				for (int j = 0; j < cursorsize; j++)
				{
					if (mousePos.y+i >= 0 && mousePos.y+i < worldheight && mousePos.x+j < worldwidth && mousePos.x+j >= 0)
					{						
					matrix[mousePos.y+i][mousePos.x+j] = selectedID;
					//std::cout << "x: " << mousePos.x << " y: " << mousePos.y << "\n"; //debug position	
					}
				}
			
			

		}

	}



}
