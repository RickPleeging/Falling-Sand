#include "pch.h"

int height = 800;
int width = 1000;

int pixelsize = 2;

int worldheight = height / pixelsize;
int worldwidth = width / pixelsize;

//Array	= [height/y/Rows]	[width/x/Columns]

Material Sand("Sand", 1);
Material Stone("Stone", 2);

int main() {

	sf::Clock clock;
	float dt; //updates per second

	std::vector<std::vector<int>> matrix(worldheight, std::vector<int>(worldwidth, 0));


	sf::RenderWindow window(sf::VideoMode(width, height), "SandWindow", sf::Style::Close);
	window.setFramerateLimit(144);

	while (window.isOpen())
	{

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			/////// RESIZE NOT IMPLEMENTED YET
			//if (event.type == sf::Event::Resized)
			//{
			//	sf::Vector2u size = window.getSize();
			//	width = size.x;
			//	height = size.y;

			//	worldheight = height / pixelsize;
			//	worldwidth = width / pixelsize;

			//	//this doesnt work for some reason
			//	matrix.resize(worldheight, std::vector<int>(worldwidth, 0));\
			//	//
			//}
			/////////
		}


		//////////////////////////////
		//		Main Loop

		//deltatime
		dt = clock.restart().asSeconds();
		std::cout << dt << "\n";


		//input
		handleinput(matrix, window);

		//Update the matrix
		updatematrix(matrix, worldheight, worldwidth, window);


		//Draw
		draw(matrix, window);





		//		Main Loop End
		//////////////////////////////
	}




	return 0;
}