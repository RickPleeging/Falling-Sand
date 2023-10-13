#include "pch.h"


extern bool pause;

void handleevents(sf::Event& event, sf::RenderWindow& window)
{
	static int cursorsize_max = 100 / pixelsize;
	static int increaserate = cursorsize_max / 5;



	// Makes Close button work
	if (event.type == sf::Event::Closed)
		window.close();
	// x to close
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::X))
		window.close();
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
			if (cursorsize > 1)
				cursorsize -= increaserate;
			break;

		case sf::Keyboard::Equal:
			if (cursorsize < cursorsize_max)
				cursorsize += increaserate;
			break;

		}


	}

	///// RESIZE NOT IMPLEMENTED YET
	/*
	if (event.type == sf::Event::Resized)
	{
		sf::Vector2u size = window.getSize();
		width = size.x;
		height = size.y;

		worldheight = height / pixelsize;
		worldwidth = width / pixelsize;

		//this doesnt work for some reason
		matrix.resize(worldheight, std::vector<int>(worldwidth, 0));
		//
	}
	*/


}