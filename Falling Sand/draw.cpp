#include "pch.h"


std::random_device rd;
std::mt19937 mt(rd());



sf::VertexArray particles(sf::Quads); // One vertex array for all particles

void initializeParticles(std::vector<std::vector<int>>& matrix) {
    particles.clear(); // Clear the existing vertex array
  

    for (int i = 0; i < worldheight; ++i) {
        for (int j = 0; j < worldwidth; ++j) {
            switch (matrix[i][j]) {
            case 1: // Sand particle
                addParticle(j * pixelsize, i * pixelsize, sf::Color::Yellow);
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

void highlightmouse()
{

}

void drawperformanceoverlay(sf::RenderWindow& window)
{
    
    sf::Text text;
    text.setFont(font); // Set the font

    std::ostringstream oss;
    oss << "Time: " << std::fixed << std::setprecision(3) << dt << " seconds";
    text.setString(oss.str());

    
    text.setCharacterSize(24); // Set the character size
    text.setFillColor(sf::Color::White); // Set the color (optional)

    window.draw(text);
}




void draw(std::vector<std::vector<int>>& matrix, sf::RenderWindow& window) {
    window.clear(sf::Color::Black);

    initializeParticles(matrix);

    //draw particles
    window.draw(particles);
    
    //draw UI
    drawperformanceoverlay(window);
 

    // Draw mouse c

    window.display();
}


