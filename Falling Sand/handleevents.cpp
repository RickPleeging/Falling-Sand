#include "pch.h"

extern bool pause;



void handleevents(sf::Event& event, sf::RenderWindow& window, Matrix& matrix,int& width, int& height)
{
	static int cursorsize_max = 100 / pixelsize;
	




	
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
					cursorsize ++;
					
				}

			}
			else if (event.mouseWheelScroll.delta < 0)
			{
				//scrolled up
				if (cursorsize > 1)
				{
					cursorsize --;
				
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

			break;

		case sf::Keyboard::Equal:

			break;
		case sf::Keyboard::H:
			if (nodraw == false)
				nodraw = true;
			else if (nodraw == true)
				nodraw = false;
			break;
		case sf::Keyboard::Period:
			if (selectedbrush < 3)
				selectedbrush++;
			break;
		case sf::Keyboard::Comma:
		
			if (selectedbrush > 1)
				selectedbrush--;
			break;
		case sf::Keyboard::Space:
			steponce = true;
		}


	}

	///// RESIZE 
	
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