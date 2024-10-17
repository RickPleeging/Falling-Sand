#include "pch.h"

extern bool pause;


void handleevents(sf::Event& event, sf::RenderWindow& window, Matrix& matrix, int& width, int& height)
{
	static int cursorsize_max = 100 / pixelsize;

	sf::Vector2i mousePos;
	sf::Vector2i oldmousePos;



	// Makes Close button work
	if (event.type == sf::Event::Closed)
		window.close();
	// x to close
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::X))
		window.close();


	if (event.type == sf::Event::MouseWheelScrolled)
	{
		if (event.mouseWheelScroll.wheel == sf::Mouse::VerticalWheel)
		{
			if (event.mouseWheelScroll.delta > 0)
			{
				//scrolled down
				if (cursorsize < cursorsize_max)
				{
					cursorsize++;

				}

			}
			else if (event.mouseWheelScroll.delta < 0)
			{
				//scrolled up
				if (cursorsize > 1)
				{
					cursorsize--;

				}

			}
		}
	}
	// Keyboard Inputs
	if (event.type == sf::Event::KeyPressed)
	{
		switch (event.key.code)
		{
		case sf::Keyboard::Escape:
			if (pause == true)
				pause = false;
			else if (pause == false)
				pause = true;
			break;

		case sf::Keyboard::Hyphen:
			if (selectedbrush > 1)
				selectedbrush--;
			break;

		case sf::Keyboard::Equal:
			if (selectedbrush < 3)
				selectedbrush++;
			break;
		case sf::Keyboard::H:
			if (nodraw == false)
				nodraw = true;
			else if (nodraw == true)
				nodraw = false;
			break;
		case sf::Keyboard::Period:
	
			break;
		case sf::Keyboard::Comma:

			
			break;
		case sf::Keyboard::F:
			for (int i = worldheight - 1; i >= 0; i--)
				for (int j = worldwidth - 1; j >= 0; j--)
				{
					matrix[i][j] = selection;
					matrix[i][j].getColor(selection.colorPalette, matrix, i, j);
				}
			break;
		case sf::Keyboard::Space:
			steponce = true;
			break;
		case sf::Keyboard::C:
			for (int i = worldheight - 1; i >= 0; i--)
				for (int j = worldwidth - 1; j >= 0; j--)
				{
					if (matrix[i][j].m_ID == selection.m_ID)
					{
						matrix[i][j] = AIR;
					}
				}
			break;
		case sf::Keyboard::Left:
			if (selectedmat > 0)
			{
				selectedmat--;
			}
			else
			{
				selectedmat = 19;
			}
			break;
		case sf::Keyboard::Right:
			if (selectedmat < 19)
			{
				selectedmat++;
			}
			else {
				selectedmat = 1;
			}
			break;
		case sf::Keyboard::D:

			sf::Vector2i mousePos = sf::Mouse::getPosition(window) / pixelsize;
			if (mousePos.y > worldheight || mousePos.y < 0 || mousePos.x > worldwidth || mousePos.x < 0)
			{
				break;
			}
			std::cout << std::endl << matrix[mousePos.y][mousePos.x].name << " X: " << mousePos.x << " Y: " << mousePos.y;
			std::cout << "\nID: " << matrix[mousePos.y][mousePos.x].m_ID;
			std::cout << "\nVelocity X: " << matrix[mousePos.y][mousePos.x].velocity_x;
			std::cout << "\nVelocity Y: " << matrix[mousePos.y][mousePos.x].velocity_y;

			std::cout << "\nWasUpdated: " << matrix[mousePos.y][mousePos.x].wasupdated;
			std::cout << "\nIs Freefaling: " << matrix[mousePos.y][mousePos.x].isfreefaling;

			std::cout << "\nHealth: " << matrix[mousePos.y][mousePos.x].health;
			std::cout << "\nIs Corrodable: " << matrix[mousePos.y][mousePos.x].corodable;
			std::cout << "\nAcidity: " << matrix[mousePos.y][mousePos.x].acidity;
			std::cout << "\nFireResistance: " << matrix[mousePos.y][mousePos.x].fireresistance;
			std::cout << "\nTemperature: " << matrix[mousePos.y][mousePos.x].temperature;



			std::cout << std::endl;
			break;
		}


	}

	/// RESIZE 

	if (event.type == sf::Event::Resized)
	{
		sf::Vector2u size = window.getSize();

		width = size.x;
		height = size.y;

		worldheight = height / pixelsize;
		worldwidth = width / pixelsize;

		matrix.resize(worldheight);
		for (int i = 0; i < worldheight; ++i)
			matrix[i].resize(worldwidth);

		sf::View view(sf::FloatRect(0, 0, width, height));
		window.setView(view);
	}
}