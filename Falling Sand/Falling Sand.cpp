#include "pch.h"
#include "Falling Sand.h"

int height = 800;
int width = 1000;

int pixelsize = 2;

int worldheight = height / pixelsize;
int worldwidth = width / pixelsize;

int selectedID = 1;




/////////////////////
//		Classes


class Material //for all materials
{
private:

public:
	
	
	std::string m_name;
	int m_id;

	Material(std::string name, int id)
	{
		this->m_id = id;
		this->m_name = name;

	}

	void updatematerial(std::vector<std::vector<int>>& matrix, int i, int j)
	{
		if (i + 1 < worldheight && matrix[i + 1][j] == 0)
		{
			/*	std::cout << "moving y: " << i;
				std::cout << "to y: " << i+1 ;
				std::cout << " Out of Max: " << worldheight << "\n";*/
			matrix[i][j] = 0;
			matrix[i + 1][j] = 1;


		}
		else if (i + 1 < worldheight && matrix[i + 1][j + 1] == 0 && matrix[i][j + 1] == 0)
		{
			matrix[i][j] = 0;
			matrix[i + 1][j + 1] = 1;
		}
		else if (i + 1 < worldheight && matrix[i + 1][j - 1] == 0 && matrix[i][j - 1] == 0)
		{
			matrix[i][j] = 0;
			matrix[i + 1][j - 1] = 1;
		}

	}

};


//		End Classes
/////////////////////

Material Sand("Sand", 1);
sf::RectangleShape sand(sf::Vector2f(pixelsize, pixelsize));
Material Stone("Stone", 2);
sf::RectangleShape stone(sf::Vector2f(pixelsize, pixelsize));

////////
////////



int main() {

	sf::Clock clock;
	float dt; //updates per second



	//Rows		=Height		= y
	//Column	=Width		= x
	// array[height][width]

	std::vector<std::vector<int>> matrix(worldheight, std::vector<int>(worldwidth, 0));




	sf::RenderWindow window(sf::VideoMode(width, height), "SandWindow", sf::Style::Default);
	window.setFramerateLimit(144);



	while (window.isOpen())
	{

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::Resized)
			{
				sf::Vector2u size = window.getSize();
				width = size.x;
				height = size.y;

				worldheight = height / pixelsize;
				worldwidth = width / pixelsize;

				//this doesnt work for some reason
				matrix.resize(worldheight, std::vector<int>(worldwidth, 0));
			}
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







/////////////////////
//		Functions

void updatematrix(std::vector<std::vector<int>>& matrix, int worldheight, int worldwidth, sf::RenderWindow& window)
{


	for (int i = worldheight - 1; i >= 0; i--)
		for (int j = worldwidth - 1; j >= 0; j--)
		{
			switch (matrix[i][j])
			{
			case 0:
				break;
			case 1:
				Sand.updatematerial(matrix, i, j);
				break;
			case 2:
				break;
				
			}
		}
}



void draw(std::vector<std::vector<int>>& matrix, sf::RenderWindow& window)
{
	window.clear(sf::Color::Black);
	//

	//create sfml squares in their respective positions
	for (int i = worldheight - 1; i >= 0; i--)
		for (int j = worldwidth - 1; j >= 0; j--)
		{
			if (matrix[i][j] == 1)
			{
				sand.setPosition(static_cast<float>(j * pixelsize), static_cast<float>(i * pixelsize));
				sand.setFillColor(sf::Color::Yellow);
				window.draw(sand);
			}
			if (matrix[i][j] == 2)
			{
				stone.setPosition(static_cast<float>(j * pixelsize), static_cast<float>(i * pixelsize));
				stone.setFillColor(sf::Color::White);
				window.draw(stone);
			}

		}

	//
	window.display();
}


void handleinput(std::vector<std::vector<int>>& matrix, sf::RenderWindow& window)
{




	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
	{
		selectedID = 1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
	{
		selectedID = 2;
	}



	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		sf::Vector2i mousePos = sf::Mouse::getPosition(window) / pixelsize;


		if (mousePos.y >= 0 && mousePos.y < worldheight && mousePos.x < worldwidth && mousePos.x >= 0)
		{
			matrix[mousePos.y][mousePos.x] = selectedID;
			// std::cout << "x: " << mousePos.x << " y: " << mousePos.y << "\n"; //debug position
		}

	}
	if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) //reset screen
	{
		for (int i = worldheight - 1; i >= 0; i--)
			for (int j = worldwidth - 1; j >= 0; j--)
				matrix[i][j] = 0;
	}


}


//		 End Functions
//////////////////////

