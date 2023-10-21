#include "pch.h"
//Array	= [height/y/Rows]	[width/x/Columns]


		//////////////////////////////
		//		Notes
		// 
		// 
		// Todo: Make Array Resizable (create buffer array copy shit over, clear and resize ....)
		// Todo: Change Array from INT to take in Elements as Parameters
		// 
		// Todo: New Elements
		// Todo: Improve Brushes
		// 
		// Todo: Convert From Console Application to Windows Application
		// Todo: Implement Menu Screen before game starts. (create 2 windows // or fix array resizing and do it in 1)
		// 
		//
		// 
		// 
		//////////////////////////////



sf::Font font;
sf::Clock deltaclock;
float dt; //updates per second



int main() {
	


	initfont();

	startup(fullscreen);
	sf::Uint32 windowstyle = sf::Style::Close;
	if (fullscreen == true)
	{
		windowstyle = sf::Style::Fullscreen;
	}

	sf::RenderWindow window(sf::VideoMode(width, height), "SandWindow", windowstyle);
	window.setFramerateLimit(144);

	std::vector<std::vector<Elements>> matrix(worldheight, std::vector<Elements>(worldwidth));


	/*for (int i = worldheight - 1; i >= 0; i--)
		for (int j = worldwidth - 1; j >= 0; j--)
		{
			matrix[i][j] = elements;
		}*/


	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			handleevents(event, window);
		}

		//////////////////////////////
		//		Main Loop
		// 

		//delta time
		dt = deltaclock.restart().asSeconds();
		
		//Create Random
		
		//std::cout << "delta: " << std::fixed << std::setprecision(3) << dt << "\n";
		
		//input
		handleinput(matrix, window, event);


			//Update the matrix
		if (pause == false || steponce == true)
		{
			updatematrix(matrix, worldheight, worldwidth, window);
			steponce = false;
		}
		

		//Draw
		// Inside your rendering function or game loop
	
		if (nodraw == false)
		draw(matrix, window, event);
		//
		//		Main Loop End
		//////////////////////////////
	}




	return 0;
}
