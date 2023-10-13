#include "pch.h"
//Array	= [height/y/Rows]	[width/x/Columns]



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

	std::vector<std::vector<int>> matrix(worldheight, std::vector<int>(worldwidth, 0));

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

		//std::cout << "delta: " << std::fixed << std::setprecision(3) << dt << "\n";
		
		//input
		handleinput(matrix, window, event);


			//Update the matrix
		if (pause == false)
			updatematrix(matrix, worldheight, worldwidth, window);
		

		//Draw
		// Inside your rendering function or game loop
	

		draw(matrix, window);
		//
		//		Main Loop End
		//////////////////////////////
	}




	return 0;
}