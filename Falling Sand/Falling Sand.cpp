#include "pch.h"
//Array	= [height/y/Rows]	[width/x/Columns]



sf::Font font;
sf::Clock deltaclock;
float dt; //updates per second

int framecount=0;

int main() {

	initfont();

	//mainmenu();


	startup(fullscreen);
	sf::Uint32 windowstyle = sf::Style::Default;
	if (fullscreen == true)
	{
		windowstyle = sf::Style::Fullscreen;
	}

	sf::RenderWindow window(sf::VideoMode(width, height), "SandWindow", windowstyle);
	window.setFramerateLimit(144);

	std::vector<std::vector<Elements>> matrix(worldheight, std::vector<Elements>(worldwidth));

	sf::View view(sf::FloatRect(0, 0, width, height));
	window.setView(view);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			handleevents(event, window,matrix,width,height);
		}

		//////////////////////////////
		//		Main Loop
		// 

		//delta time
		dt = deltaclock.restart().asSeconds();
		

		FPS = static_cast<int>(1.0f / dt);
		
		


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
