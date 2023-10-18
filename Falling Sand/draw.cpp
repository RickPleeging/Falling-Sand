#include "pch.h"


std::random_device rd;
std::mt19937 mt(rd());

sf::VertexArray mousehighlight(sf::LineStrip);


sf::VertexArray particles(sf::Quads); // One vertex array for all particles

void initializeParticles(std::vector<std::vector<Pixels>>& matrix) {
    particles.clear(); // Clear the existing vertex array
  

    for (int i = 0; i < worldheight; ++i) {
        for (int j = 0; j < worldwidth; ++j) {
            switch (matrix[i][j].ID) {
            case 1: // Sand particle
                addParticle(j * pixelsize, i * pixelsize, sf::Color::Yellow);
                break;

            case 2: // Stone particle
                addParticle(j * pixelsize, i * pixelsize, sf::Color::White);
                break;
                // Add more cases for other particle types if needed

            case 3: //Water
                addParticle(j * pixelsize, i * pixelsize, sf::Color::Blue);
                break;
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



void highlightmouse(sf::RenderWindow& window) // this cost me my sanity but it FUCKING WORKS FINNALY
{
    mousehighlight.clear();

    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    int totalsize = (cursorsize * pixelsize)-pixelsize;

    int rowindex = mousePos.y / pixelsize;
    int colindex = mousePos.x / pixelsize;

    int startX = (colindex * pixelsize);
    int startY = (rowindex * pixelsize);
    int endX = ((colindex + 1) * pixelsize);
    int endY = ((rowindex + 1) * pixelsize);


	mousehighlight.append(sf::Vertex(sf::Vector2f(startX - totalsize, startY - totalsize), sf::Color::Green));
	mousehighlight.append(sf::Vertex(sf::Vector2f(endX + totalsize, startY - totalsize), sf::Color::Green));
	mousehighlight.append(sf::Vertex(sf::Vector2f(endX + totalsize, endY + totalsize), sf::Color::Green));
	mousehighlight.append(sf::Vertex(sf::Vector2f(startX - totalsize, endY + totalsize), sf::Color::Green));
	mousehighlight.append(sf::Vertex(sf::Vector2f(startX - totalsize, startY - totalsize), sf::Color::Green));
}

void draw_performanceoverlay(sf::RenderWindow& window)
{
    
    sf::Text t_deltatime;
    t_deltatime.setFont(font); // Set the font

    std::ostringstream dtstring;
    dtstring << "Time: " << std::fixed << std::setprecision(3) << dt << " seconds";
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


void draw(std::vector<std::vector<Pixels>>& matrix, sf::RenderWindow& window,sf::Event& event) {
    window.clear(sf::Color(55,55,55,255));

    initializeParticles(matrix);

    //draw particles
    window.draw(particles);
    
    //draw UI
    draw_performanceoverlay(window);
    drawgameoverlay(window);

    // Draw mouse c
    if (event.type == sf::Event::MouseMoved || event.type == sf::Event::MouseWheelScrolled)
    { 
    highlightmouse(window);
    }
    window.draw(mousehighlight);
    //Display
    window.display();
}