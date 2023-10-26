#include "pch.h"
#include "Falling Sand.h"
#include "globals.h"
int ammount_created_pixels;



void handleinput(std::vector<std::vector<Elements>>& matrix, sf::RenderWindow& window, sf::Event& event)
{
	
	//swap selcted material

	


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num0))
	{
		selection = AIR;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
	{
		selection = SAND;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
	{
		selection = WATER;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
	{
		selection = STONE;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4))
	{
		selection = SMOKE;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num9))
	{
		selection = BLACKHOLE;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
		{
			spawnID = 1;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
		{
			spawnID = 2;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4))
		{
			spawnID = 4;
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) //reset screen
	{
		for (int i = worldheight - 1; i >= 0; i--)
			for (int j = worldwidth - 1; j >= 0; j--)
				matrix[i][j].m_ID = 0;
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

							matrix[mousePos.y + i][mousePos.x + j] = selection;
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
							
							matrix[mousePos.y + i][mousePos.x + j] = selection;
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
							
							matrix[mousePos.y + i][mousePos.x + j] = selection;
							//std::cout << "x: " << mousePos.x << " y: " << mousePos.y << "\n"; //debug position	
						}
					}
				break;
			}	
		}
	}

	if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
	{
		sf::Vector2i mousePos = sf::Mouse::getPosition(window) / pixelsize;

		if (mousePos.y >= 0 && mousePos.y < worldheight && mousePos.x < worldwidth && mousePos.x >= 0)
		{
			//matrix[mousePos.y][mousePos.x] = Spawners();

			matrix[mousePos.y][mousePos.x] = SPAWNER;
			matrix[mousePos.y][mousePos.x].m_spawnID = spawnID;
			//std::cout << "x: " << mousePos.x << " y: " << mousePos.y << "\n"; //debug position	
		}
	}
}