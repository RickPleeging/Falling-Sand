#include "pch.h"

sf::VertexArray particles(sf::Quads); // One vertex array for all particles

void initializeParticles(std::vector<std::vector<int>>& matrix) {
    particles.clear(); // Clear the existing vertex array

    for (int i = 0; i < worldheight; ++i) {
        for (int j = 0; j < worldwidth; ++j) {
            switch (matrix[i][j]) {
            case 1: // Sand particle
                addParticle(j * pixelsize, i * pixelsize, sf::Color(255,255,255,255));
                break;
            case 2: // Stone particle
                addParticle(j * pixelsize, i * pixelsize, sf::Color::White);
                break;
                // Add more cases for other particle types if needed
            }
        }
    }
}

void addParticle(float x, float y, const sf::Color& color) {
    particles.append(sf::Vertex(sf::Vector2f(x, y), color));
    particles.append(sf::Vertex(sf::Vector2f(x + pixelsize, y), color));
    particles.append(sf::Vertex(sf::Vector2f(x + pixelsize, y + pixelsize), color));
    particles.append(sf::Vertex(sf::Vector2f(x, y + pixelsize), color));
}

void draw(std::vector<std::vector<int>>& matrix, sf::RenderWindow& window) {
    window.clear(sf::Color::Black);

    initializeParticles(matrix);

    window.draw(particles);

    // Draw mouse cursor or other additional elements if needed

    window.display();
}



//my code was hella slow and chatgpt did it better :(

/*
#include "pch.h"

sf::RectangleShape sand(sf::Vector2f(static_cast<float>(pixelsize), static_cast<float>(pixelsize)));
sf::RectangleShape stone(sf::Vector2f(static_cast<float>(pixelsize), static_cast<float>(pixelsize)));






void draw(std::vector<std::vector<int>>& matrix, sf::RenderWindow& window)
{
	window.clear(sf::Color::Black);
	
	stone.setFillColor(sf::Color::White);
	sand.setFillColor(sf::Color::Yellow);



	for (int i = worldheight - 1; i >= 0; i--)
		for (int j = worldwidth - 1; j >= 0; j--)
		{
			switch (matrix[i][j])
			{
			case 1:

				sand.setPosition(static_cast<float>(j * pixelsize), static_cast<float>(i * pixelsize));
				window.draw(sand);
				break;
			case 2:
				stone.setPosition(static_cast<float>(j * pixelsize), static_cast<float>(i * pixelsize));
				window.draw(stone);
				break;
			}


		}



		//draw mouse cursor

	//
	window.display();
}
*/
