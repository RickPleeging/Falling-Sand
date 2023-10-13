#include "pch.h"
#include "Falling Sand.h"

int ammount_created_pixels;

void handleinput(std::vector<std::vector<int>>& matrix, sf::RenderWindow& window, sf::Event& event)
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
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) //reset screen
	{
		for (int i = worldheight - 1; i >= 0; i--)
			for (int j = worldwidth - 1; j >= 0; j--)
				matrix[i][j] = 0;
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
						
						//count pixels (REALLY SLOW)
						/*ammount_created_pixels++;
						std::cout << "\nCreated Pixels total: " << ammount_created_pixels;*/
					

					

					}
				}
			
			

		}

	}



}
