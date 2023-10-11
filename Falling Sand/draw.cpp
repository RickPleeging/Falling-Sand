#include "pch.h"

sf::RectangleShape sand(sf::Vector2f(static_cast<float>(pixelsize), static_cast<float>(pixelsize)));
sf::RectangleShape stone(sf::Vector2f(static_cast<float>(pixelsize), static_cast<float>(pixelsize)));


void draw(std::vector<std::vector<int>>& matrix, sf::RenderWindow& window)
{
	window.clear(sf::Color::Black);
	//

	//create sfml squares in their respective positions
	for (int i = worldheight - 1; i >= 0; i--)
		for (int j = worldwidth - 1; j >= 0; j--)
		{
			switch (matrix[i][j])
			{
			case 1:
				sand.setPosition(static_cast<float>(j * pixelsize), static_cast<float>(i * pixelsize));
				sand.setFillColor(sf::Color::Yellow);
				window.draw(sand);
				break;
			case 2:
				stone.setPosition(static_cast<float>(j * pixelsize), static_cast<float>(i * pixelsize));
				stone.setFillColor(sf::Color::White);
				window.draw(stone);
				break;
			}


		}

	//
	window.display();
}
