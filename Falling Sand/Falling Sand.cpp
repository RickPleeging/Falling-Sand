#include "pch.h"


//Array	= [height/y/Rows]	[width/x/Columns]

Material Sand("Sand", 1);
Material Stone("Stone", 2);




int main() {


	


	sf::Uint32 windowstyle = sf::Style::Close;

	if (startup() == true)
	{
		windowstyle = sf::Style::Fullscreen;
	}


	sf::Clock clock;
	float dt; //updates per second


	

	sf::RenderWindow window(sf::VideoMode(width, height), "SandWindow", windowstyle);
	window.setFramerateLimit(144);

	std::vector<std::vector<int>> matrix(worldheight, std::vector<int>(worldwidth, 0));

	while (window.isOpen())
	{

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::X))
				window.close();


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
			///////
		}


		//////////////////////////////
		//		Main Loop

		//deltatime
		dt = clock.restart().asSeconds();

		std::cout << "delta: " << std::fixed << std::setprecision(3) << dt << "\n";
	


		//input
		handleinput(matrix, window, event);

		//Update the matrix
		updatematrix(matrix, worldheight, worldwidth, window);


		//Draw
		draw(matrix, window);





		//		Main Loop End
		//////////////////////////////
	}




	return 0;
}