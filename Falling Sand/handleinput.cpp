#include "pch.h"
#include "Falling Sand.h"
#include "globals.h"


void handleinput(std::vector<std::vector<Elements>>& matrix, sf::RenderWindow& window, sf::Event& event)
{
	
	//swap selcted material

	


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num0))
	{
		selection = AIR;
		selectedmat = 0;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
	{
		selection = SAND;
		selectedmat = 1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
	{
		selection = WATER;
		selectedmat = 2;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
	{
		selection = STONE;
		selectedmat = 3;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4))
	{
		selection = SMOKE;
		selectedmat = 4;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num5))
	{
		selection = ACID;
		selectedmat = 5;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num6))
	{
		selection = FLAMMABLEGAS;
		selectedmat = 6;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num7))
	{
		selection = GLASS;
		selectedmat = 7;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num8))
	{
		selection = WOOD;
		selectedmat = 8;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num9))
	{
		selection = BLACKHOLE;
		selectedmat = 9;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
	{
		selection = STATICFIRE;
		selectedmat = 10;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
	{
		selection = STEAM;
		selectedmat = 11;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
	{
		
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) //reset screen
	{
		for (int i = worldheight - 1; i >= 0; i--)
			for (int j = worldwidth - 1; j >= 0; j--)
				matrix[i][j].m_ID = 0;
	}

	switch (selectedmat)
	{
	case 0:
		selection = AIR;
		break;
	case 1:
		selection = SAND;
		break;
	case 2:
		selection = WATER;
		break;
	case 3:
		selection = STONE;
		break;
	case 4:
		selection = SMOKE;
		break;
	case 5:
		selection = ACID;
		break;
	case 6:
		selection = FLAMMABLEGAS;
		break;
	case 7:
		selection = GLASS;
		break;
	case 8:
		selection = WOOD;
		break;
	case 9:
		selection = BLACKHOLE;
		break;
	case 10:
		selection = STATICFIRE;
		break;
	case 11:
		selection = STEAM;
		break;
	case 12:
		selection = LAVA;
		break;
	case 13:
		selection = OIL;
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
			matrix[mousePos.y][mousePos.x].m_spawnID = selection.m_ID;
			//std::cout << "x: " << mousePos.x << " y: " << mousePos.y << "\n"; //debug position	
		}
	}
}