#include "pch.h"
#include "Falling Sand.h"

int ammount_created_pixels;


void handleinput(std::vector<std::vector<Pixels>>& matrix, sf::RenderWindow& window, sf::Event& event)
{

	//swap selcted material


	


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num0))
	{
		selectedID = 0;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
	{
		selectedID = 1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
	{
		selectedID = 2;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
	{
		selectedID = 3;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) //reset screen
	{
		for (int i = worldheight - 1; i >= 0; i--)
			for (int j = worldwidth - 1; j >= 0; j--)
				matrix[i][j].ID = 0;
	}
	




	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		srand(time(NULL));
		sf::Vector2i mousePos = sf::Mouse::getPosition(window) / pixelsize;


		if (mousePos.y >= 0 && mousePos.y < worldheight && mousePos.x < worldwidth && mousePos.x >= 0)
		{
		
			
			

			switch (selectedbrush)
			{
			case 1: // brush 1
				for (int i = 1 - cursorsize; i < cursorsize; i++)
					for (int j = 1 - cursorsize; j < cursorsize; j++)
					{
						if (mousePos.y + i >= 0 && mousePos.y + i < worldheight && mousePos.x + j < worldwidth && mousePos.x + j >= 0)
						{

							matrix[mousePos.y + i][mousePos.x + j].ID = selectedID;
							//std::cout << "x: " << mousePos.x << " y: " << mousePos.y << "\n"; //debug position	
						}
					}
				break;
			case 2: // brush 2

				
				
				for (int i = 1 - cursorsize; i < cursorsize; i++)
					for (int j = 1 - cursorsize; j < cursorsize; j++)
					{
						int rng1 = rand() % 100 + 1;
						if (mousePos.y + i >= 0 && mousePos.y + i < worldheight && mousePos.x + j < worldwidth && mousePos.x + j >= 0 && rng1 < 5)
						{
							
							matrix[mousePos.y + i][mousePos.x + j].ID = selectedID;
							//std::cout << "x: " << mousePos.x << " y: " << mousePos.y << "\n"; //debug position	
						}
					}
				break;
			case 3: // brush 3
				for (int i = 1 - cursorsize; i < cursorsize; i++)
					for (int j = 1 - cursorsize; j < cursorsize; j++)
					{
						int rng1 = rand() % 100 + 1;
						if (mousePos.y + i >= 0 && mousePos.y + i < worldheight && mousePos.x + j < worldwidth && mousePos.x + j >= 0 && rng1 < 5)
						{
							
							matrix[mousePos.y + i][mousePos.x + j].ID = selectedID;
							//std::cout << "x: " << mousePos.x << " y: " << mousePos.y << "\n"; //debug position	
						}
					}
				break;
			
			}
			
			
			

		}

	}



}
