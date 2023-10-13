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

void draw_performanceoverlay(sf::RenderWindow& window)
{
    
    sf::Text t_deltatime;
    t_deltatime.setFont(font); // Set the font

    std::ostringstream dtstring;
    dtstring << "Time: " << std::fixed << std::setprecision(3) << dt << " ms";
    t_deltatime.setString(dtstring.str());

    
    t_deltatime.setCharacterSize(15); // Set the character size
    t_deltatime.setFillColor(sf::Color::White); // Set the color (optional)

    window.draw(t_deltatime);
}

void drawgameoverlay(sf::RenderWindow& window)
{
    sf::Text t_selectedMaterial;
    t_selectedMaterial.setFont(font);
    t_selectedMaterial.setFillColor(sf::Color::White);
    t_selectedMaterial.setCharacterSize(20);
    t_selectedMaterial.setPosition(150, 0);

    std::ostringstream materialstring;
    materialstring << "Selected Material: " << selectedID;
    t_selectedMaterial.setString(materialstring.str());

    window.draw(t_selectedMaterial);

    if (pause == true)
    {
        sf::Text t_paused;
        t_paused.setFont(font);
        t_paused.setFillColor(sf::Color::White);
        t_paused.setCharacterSize(30);
        t_paused.setLetterSpacing(2);
        t_paused.setPosition(0,60);

        t_paused.setString("Paused!");
        window.draw(t_paused);

    }
    
}


void draw(std::vector<std::vector<int>>& matrix, sf::RenderWindow& window) {
    window.clear(sf::Color::Black);

    initializeParticles(matrix);

    //draw particles
    window.draw(particles);
    
    //draw UI
    draw_performanceoverlay(window);
    drawgameoverlay(window);


    // Draw mouse c

    window.display();
}


